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

void solve() {
    ll n;
    cin>>n;
    vv<ll> adj(n+1);
    REP(i, n-1) {
        ll a, b;
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    if (n<=2) {
        cout<<n<<"\n";
        FORN(i, 1, n) cout<<i<<" "<<0<<"\n";
        return;
    }

    vll d(n+1, -1), par(n+1);
    function<void(ll, ll)> dfs = [&] (ll v, ll p) {
        par[v] = p;
        d[v] = d[p]+1;
        for (auto c: adj[v]) if (c!=p) dfs(c, v);
    };

    dfs(1, 0);
    ll m = max_element(all(d)) - d.begin();
    dfs(m, 0);
    ll a = max_element(all(d)) - d.begin();
    dfs(a, 0);
    ll b = max_element(all(d)) - d.begin();

    ll diam = d[b];

    ll v = b;
    vll midp;

    do {
        v = par[v];
        if (d[v] == diam/2 || d[v] == diam - diam/2) midp.eb(v);
    } while (v!=a);

    deb(midp, diam);

    vector<pair<ll, ll>> ans;
    ll k = (diam+1)/2;
    if (diam&1)
        for (int i=1;i<=k;i+=2) {
            ans.eb(midp[0], i);
            ans.eb(midp[1], i);
        }
    else FORN(i, 0, k) ans.eb(midp[0], i);

    cout<<ans.size()<<"\n";
    for (auto &[x, y]: ans) cout<<x<<" "<<y<<"\n";
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
