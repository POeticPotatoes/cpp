#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll n, m, a, b;
vv<ll> adj;
vector<array<int, 2>> s;
vll pole, vis;

bool dfs1(ll v) {
    // deb(v, p);
    vis[v] = 1;
    bool flag = 0;
    s[v][0] = pole[v] == 0;
    s[v][1] = pole[v] == 1;
    for (auto c: adj[v]) {
        if (vis[c]) {
            flag |= pole[c] == pole[v];
            continue;
        }
        pole[c] = pole[v]^1;
        flag |= dfs1(c);
        s[v][0] += s[c][0];
        s[v][1] += s[c][1];
    }
    return flag;
}

void solve() {
    cin>>n>>m;
    adj = vv<ll>(n+1);
    vis = vll(n+1);
    pole = vll(n+1);
    s = vector<array<int, 2>>(n+1);
    REP(i, m) {
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    ll ans = 0;
    FORN(i, 1, n) {
        if (vis[i]) continue;
        // deb(i);
        if (dfs1(i)) {
            ll sz = s[i][0] + s[i][1];
            ans += sz*sz;
        } else {
            ans += s[i][0] * s[i][0];
            ans += s[i][1] * s[i][1];
        }
        // deb(s[i]);
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
