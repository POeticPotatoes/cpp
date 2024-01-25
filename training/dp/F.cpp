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

void solve() {
    ll n;
    cin>>n;
    vv<ll> adj(n+1);
    vll sz(n+1);
    FORN(i, 2, n) {
        ll c;
        cin>>c;
        adj[c].eb(i);
    }
    
    function<ll(ll)> dfs = [&] (ll v) {
        sz[v] = 1;
        for (auto c: adj[v]) sz[v] += dfs(c);
        return sz[v];
    };

    dfs(1);
    deb(sz);

    ll ans=0;
    function<void(ll, ll)> dfs2 = [&] (ll v, ll matched) {
        deb(v, matched, ans);
        if (matched) matched--;
        if (sz[v]==1) return;
        ll m = 0;
        REP(i, (ll) adj[v].size()) if (sz[adj[v][i]] > sz[adj[v][m]]) m = i;
        ll c = adj[v][m];

        if (sz[c]-matched <= (sz[v]-1-matched)/2) {
            ans += (sz[v]-1-matched)/2;
            return;
        }

        ans += sz[v] -1 -sz[c];
        dfs2(c, matched + (sz[v]-1-sz[c]));
    };

    dfs2(1, 0);
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
