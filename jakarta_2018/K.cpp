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
    ll n, m;
    cin>>n>>m;

    vv<ll> adj(n+1);
    REP(i, m) {
        ll a, b;
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    vll vis(n+1);
    vector<array<ll, 3>> ans;

    function<ll(ll, ll)> dfs = [&] (ll v, ll p) {
        vis[v] = 1;
        ll prev = 0;
        for (auto c: adj[v]) {
            if (vis[c] == 1) continue;
            if (vis[c] == 2) {
                if (prev) {
                    ans.push_back(array<ll, 3>{prev, v, c});
                    prev = 0;
                } else prev = c;
                continue;
            }
            if (dfs(c, v)) {
                if (prev) {
                    ans.push_back(array<ll, 3>{prev, v, c});
                    prev = 0;
                } else prev = c;
            }
        }
        vis[v] = 2;
        if (prev && p) {
            ans.push_back(array<ll, 3>{prev, v, p});
            return 0;
        }
        return 1;
    };

    FORN(i, 1, n) {
        if (!vis[i]) dfs(i, 0);
    }
    cout<<ans.size()<<"\n";
    REP(i, ans.size()) {
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<"\n";
    }
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
