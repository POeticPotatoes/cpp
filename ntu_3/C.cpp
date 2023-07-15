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

const ll N = 1e6;
ll n, A[N];

void solve() {
    cin>>n;
    vv<ll> adj(n+1);
    vector<bool> val(n+1);
    // IN, NOT, AND, OR, XOR
    vector<int> type(n+1);
    FORN(i, 1, n) {
        string s;
        int a, b;
        cin>>s;
        cin>>a;
        if (s == "NOT") {
            type[i] = 1;
            adj[i].eb(a);
        } else if (s == "IN") {
            val[i] = a;
        } else if (s == "AND") {
            cin>>b;
            deb(a, b);
            type[i] = 2;
            adj[i].eb(a);
            adj[i].eb(b);
            break;
        } else if (s == "OR") {
            cin>>b;
            type[i] = 3;
            adj[i].eb(a);
            adj[i].eb(b);
            break;
        } else if (s == "XOR") {
            cin>>b;
            type[i] = 4;
            adj[i].eb(a);
            adj[i].eb(b);
            break;
        }
    }

    function<bool(int)> dfs = [&](int v) {
        if (!type[v]) return val[v];
        switch(type[v]) {
            case 1: return val[v] = !dfs(adj[v][0]);
            case 2: return val[v] = dfs(adj[v][0]) & dfs(adj[v][1]);
            case 3: return val[v] = dfs(adj[v][0]) | dfs(adj[v][1]);
            case 4: return val[v] = dfs(adj[v][0]) ^ dfs(adj[v][1]);
        }
    };
    bool orig = dfs(1);
    vll ans(n+1, orig);
    function<void(int)> flip = [&](int v) {
        if (!type[v]) ans[v] = !ans[v];
        switch(type[v]) {
            case 1: return (void) flip (adj[v][0]);
            case 2:
                if (val[v]) {
                    flip(adj[v][0]);
                    flip(adj[v][1]);
                } else {
                    if (val[adj[v][0]]) flip(adj[v][1]);
                    if (val[adj[v][1]]) flip(adj[v][0]);
                }
                break;
            case 3:
                if (!val[v]) {
                    flip(adj[v][0]);
                    flip(adj[v][1]);
                } else {
                    if (!val[adj[v][0]]) flip(adj[v][1]);
                    if (!val[adj[v][1]]) flip(adj[v][0]);
                }
                break;
            case 4:
                flip(adj[v][0]);
                flip(adj[v][1]);
                break;
        }
    };
    FORN(i, 1, n) cout<<val[i];
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
