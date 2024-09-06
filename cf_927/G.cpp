#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;
#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll i = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vv<T>>;
template <typename T, typename N>
using um = unordered_map<T, N>;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ll MOD[] = {999727999, 1070777777, 1000000007, 998244353};
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
const int M = MOD[2];
const int inf = (int)1e9;
const ll INF = 1e18;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void solve() {
    ll n, m, H;
    cin>>n>>m>>H;
    
    vll A(n+1), B(n+1);
    FORN(i, 1, n) cin>>A[i];
    FORN(i, 1, n) cin>>B[i];
    FORN(i, 1, n) B[i]%=H;

    vv<ll> adj(n+1);
    REP(i, m) {
        ll a, b;
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    deb(adj);

    vll vis(n+1);
    MinHeap<pair<ll, ll>> T;


    auto nxt = [&] (ll t, ll a, ll b) {
        ll x = (((B[a]*((t-1)%H))%H) + A[a])%H;
        ll y = (((B[b]*((t-1)%H))%H) + A[b])%H;
        ll d = ((x-y) % H + H) %H;
        ll diff = ((B[b]-B[a])%H+H) %H;
        // diff-a H-b d-c
        ll u, v, g;

        if (!find_any_solution(diff, H, d, u, v, g)) return -1LL;
        ll m = H/g;
        u = (u%m+m)%m;
        deb(x, y, d, diff, u);
        return t+u;
    };

    T.push({0, 1});
    while (T.size()) {
        auto [t, v] = T.top(); T.pop();
        deb(t, v);
        if (vis[v]) continue;
        if (v==n) return (void) (cout<<t<<"\n");
        vis[v] = 1;
        for (auto c: adj[v]) {
            if (!vis[c]) {
                ll x = nxt(t+1, v, c);
                if (x!=-1) T.push({x, c});
            }
        }
    }
    cout<<"-1\n";
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
