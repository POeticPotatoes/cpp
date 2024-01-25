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

void solve() {
    int n, th; cin >> n >> th;
    vector<int> g[n+2];
    int wt[n+2];
    wt[0] = wt[1] = 0;

    REP(i, n) {
        int x, y, z, w; cin >> x >> y >> z >> w;
        g[z].push_back(x);
        g[y].push_back(x);
        wt[x] = w;
    }
    vector<pair<int, ll>> ans;

    FOR(i, 2, n+2){
        queue<int> q;
        vector<bool> vis(n+2, false);
        q.push(i);
        ll sum = 0;
        while (q.size()){
            int u = q.front();
            q.pop();
            vis[u] = true;
            sum += wt[u];
            for (int v:g[u]){
                if (!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        if (sum >= th) ans.push_back({i, sum});
    }
    for (auto xx:ans) {
        cout << xx.first << ' ' << xx.second << '\n';
    }
    cout << ans.size() << endl;


    
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
