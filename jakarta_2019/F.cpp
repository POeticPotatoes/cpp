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
    vv<int> adj(n+1);
    vector<multiset<int>> b(n+1);
    vll hash(n+1), sz(n+1);
    map<multiset<int>,int> lookup;
    lookup[multiset<int>()] = 1;

    REP(i, n-1) {
        ll x, y;
        cin>>x>>y;
        adj[x].eb(y);
        adj[y].eb(x);
    }
    if (n == 1) return (void) (cout<<"0\n");

    ll root = 0;

    function<int(int, int)> sz1 = [&] (ll v, ll p) {
        sz[v]=1;
        for (auto c: adj[v]) if (c != p) sz[v] += sz1(c, v);
        return sz[v];
    };

    function<void(int, int)> sz2 = [&] (ll v, ll p) {
        if (adj[v].size() == 1 && p) return;
        ll size = n - sz[v];
        bool flag = true;
        for (auto c: adj[v]) if (c != p) {
            flag &= sz[c] == size;
            sz2(c, v);
        }
        if (flag) {
            assert(root==0);
            root = v;
        }
    };

    sz1(1, 0);
    sz2(1, 0);
    deb(sz);

    if (!root) return (void) (cout<<"-1\n");
    deb(root);

    function<int(multiset<int> &)> getId = [&] (multiset<int> &s) {
        int id = lookup[s];
        if (!id) {
            id = lookup.size()+1;
            lookup[s] = id;
        }
        return id;

    };

    function<int(int, int)> dfs1 = [&] (int v, int p) {
        REP(i, adj[v].size()) if (adj[v][i] != p) {
            b[v].emplace(dfs1(adj[v][i], v));
        }
        hash[v] = getId(b[v]);
        return hash[v];
    };

    function<void(int, int, int)> dfs2 = [&] (int v, int p, int h) {
        if (h != -1) {
            b[v].emplace(h);
            hash[v] = getId(b[v]);
        }
        
        REP(i, adj[v].size()) if (adj[v][i] != p) {
            int c = hash[adj[v][i]];
            b[v].erase(b[v].find(c));
            dfs2(adj[v][i], v, getId(b[v]));
            b[v].emplace(c);
        }
    };

    for (auto c: adj[root]) dfs1(c, root);
    deb(b);
    deb(hash);
    dfs2(adj[root][0], root, -1);

    set<int> avail;
    function<void(int, int)> addItems = [&] (int v, int p) {
        avail.emplace(hash[v]);
        for (auto c: adj[v]) if (c != p) addItems(c, v);
    };
    addItems(adj[root][0], root);
    deb(avail);

    FOR(i, 1, adj[root].size())
        if (!avail.count(hash[adj[root][i]])) return (void) (cout<<"-1\n");
    cout<<adj[root].size()<<"\n";
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
