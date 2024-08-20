#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
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

int n, l;
vector<vector<int>> adj;
int timer;
vector<int> A, tin, tout, depth;
vector<vector<int>> up, use, res;

void dfs(int v, int p, vector<int> u, int d) {
    depth[v] = d;
    tin[v] = ++timer;
    up[v][0] = p;
    res[v][0] = A[p]|A[v];
    for(int i=1;i<=l;i++)
        up[v][i] = up[up[v][i-1]][i-1];
    for(int i=1;i<=l;i++)
        res[v][i] = res[v][i-1] | res[up[v][i-1]][i-1];

    use[v] = u;
    REP(i, 31)
        if (A[v]>>i&1) u[i] = v;

    for (int c: adj[v])
        if (c != p) dfs(c,v, u, d+1);
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i=l;i>=0; --i) {
        if (!is_ancestor(up[u][i], v))
            u=up[u][i];
    }
    return up[u][0];
}

int OR(ll u, ll dist) {
    ll ans = A[u];
    REP(i, 31) {
        if (dist>>i&1) {
            ans |= res[u][i];
            u = up[u][i];
        }
    }
    return ans;
}

int query(int u, int v) {
    int lc = lca(u, v);
    ll ans = 0;
    ans = OR(u, depth[u]-depth[lc]) | OR(v, depth[v]-depth[lc]);
    // deb("query", u, v, ans);
    return ans;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    timer=0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l+1));
    res.assign(n, vector<int>(l+1));
    use.assign(n, vector<int>(31));
    dfs(root, root, vector<int>(31, -1), 0);
}

void solve() {
    cin>>n;
    A = vector<int>(n);
    adj = vector<vector<int>>(n);
    REP(i, n) cin>>A[i];
    REP(i, n-1) {
        ll a, b;
        cin>>a>>b;
        adj[--a].eb(--b);
        adj[b].eb(a);
    }
    preprocess(0);
    // deb(up, use, res);
    
    ll q;
    cin>>q;

    REP(i, q) {
        ll u, v;
        cin>>u>>v;
        u--, v--;
        ll lc = lca(u, v);
        // deb(lc);

        vll useful;
        useful.eb(u);
        useful.eb(v);
        REP(j, 31) {
            if (use[u][j] != -1 && depth[lc] <= depth[use[u][j]]) 
                useful.eb(use[u][j]);
            if (use[v][j] != -1 && depth[lc] <= depth[use[v][j]]) 
                useful.eb(use[v][j]);
        }

        ll ans=__builtin_popcountll(A[u]|A[v]);
        for (auto x: useful) {
            // deb(x);
            ll val = __builtin_popcountll(query(u, x))
                + __builtin_popcountll(query(x, v));
            ans = max(ans, val);
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
