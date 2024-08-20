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
    ll n, k;
    cin>>n>>k;

    vll A(n+1);;
    REP(i, k) {
        ll c;
        cin>>c;
        A[c] = 1;
    }
    vv<ll> adj(n+1);
    vector<map<ll, ll>> dist(n+1);
    REP(i, n-1) {
        ll a, b;
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    function<ll(ll, ll)> dfs1 = [&] (ll v, ll p) {
        ll m= A[v]?0:-INF;
        for (auto c: adj[v]) if (c!=p) {
            dist[v][c] = dfs1(c, v);
            m = max(m, dist[v][c]);
        }
        return m+1;
    };

    ll ans = INF;
    function<void(ll, ll, ll)> dfs2 = [&] (ll v, ll p, ll d) {
        multiset<ll, greater<ll>> dists;
        dists.insert(d);
        if (A[v]) dists.insert(0);

        for (auto &[a, b]: dist[v]) dists.insert(b);
        //deb(v, dists, d, *dists.begin());
        ans = min(ans, *dists.begin());

        for (auto &[a, b]: dist[v]) {
            dists.erase(dists.find(b));
            dfs2(a, v, *dists.begin() + 1);
            dists.insert(b);
        }
    };

    dfs1(1, 1);
    //deb(dist);
    dfs2(1, 1, -INF);

    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
