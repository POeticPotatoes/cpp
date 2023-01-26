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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 2e5;

int n, m, d, vis[N], A[N][2], a, b, ans;
vv<int> adj;

int &get(pair<int, int> &p, int i) { return i?p.second:p.first; }

pair<int, int> dfs(int k, pair<int, int> p, int depth) {
    deb(k+1, p, depth);
    vis[k] = 1;
    pair<int, int> lower;
    REP(i, 2) {
        if (A[k][i]) {
            int &j = get(p, i), &l = get(p, i^1);
            ans += depth - j;
            j = depth;
            if (depth - l > d)
                ans += depth-d-l, l = depth-d;
        }
    }
    deb(p, ans);
    for (auto i: adj[k]) {
        if (vis[i]) continue;
        auto p2 = dfs(i, p, depth+1);
        deb(p2);
        REP(j, 2) {
            int &l = get(p2, j);
            if (l > depth) {
                get(lower, j) |= 1;
                get(p, j) = 2*depth - l;
            } else get(p, j) = l;
            deb(j, get(p, j), l);
        }
    }
    deb(k+1, ans, lower, p);
    return {lower.first? 2*depth - p.first: p.first, lower.second? 2*depth - p.second: p.second};
}


void solve() {
    cin>>n>>d;
    adj = vv<int>(n);
    REP(i, n-1) {
        cin>>a>>b;
        adj[--a].eb(--b);
        adj[b].eb(a);
    }
    memset(A, 0, sizeof(int[2])*n);
    memset(vis, 0, sizeof(int)*n);
    REP(j, 2) {
        cin>>m;
        REP(i, m) {
            cin>>a;
            A[--a][j]=1;
        }
    }
    ans = 0;
    auto p = dfs(0, {0, 0}, 0);
    deb(p);
    ans += p.first + p.second;
    cout<<ans<<endl;
}

int main() {
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
