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
    ll n, m;
    cin>>n>>m;
    vv<ll> mat(n+1, vll(n+1, INF));
    REP(i, m) {
        ll a, b, w;
        cin>>a>>b>>w;
        mat[a][b] = min(mat[a][b], w);
        mat[b][a] = min(mat[b][a], w);
    }
    vv<pair<ll, ll>> adj(n+1);
    FORN(i, 1, n) FORN(j, 1, n) {
        if (mat[i][j]<INF) adj[i].eb(j, mat[i][j]);
    }
    vll slo(n+1);
    FORN(i, 1, n) cin>>slo[i];

    const ll N = 1000;
    vll vis((n+1)*(N+1), INF);

    MinHeap<pair<ll, ll>> Q;
    Q.emplace(0, (N+1) + slo[1]);

    while (Q.size()) {
        auto [d, r] = Q.top(); Q.pop();

        if (vis[r] <= d) continue;
        vis[r] = d;

        ll v = r/(N+1), o = min(slo[v], r%(N+1));
        deb(v, o, d);
        if (v==n) return (void) (cout<<d<<"\n");

        for (auto &[c, w]: adj[v]) {
            Q.emplace(d + o*w, (N+1)*c+o);
        }
    }
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
