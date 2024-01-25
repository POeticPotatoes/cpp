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

const ll N = 2e5;

ll fac[N+1], inv[N+1];

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans * ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

void init() {
    fac[0] = 1;
    FORN(i, 1, N) fac[i] = (fac[i-1] * i) %M;
    inv[N] = modPow(fac[N], M-2);
    ROF(i, N, 0) inv[i-1] = (inv[i] * i) %M;
}

ll choose(ll a, ll b) {
    if (b>a) return 0;
    return ((fac[a]*inv[a-b])%M * inv[b]) %M;
}

void solve() {
    ll n, k;
    cin>>n>>k;

    vv<ll> adj(n+1);
    vll sz(n+1);

    REP(i, n-1) {
        ll a, b;
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    if (k&1) return (void) (cout<<"1\n");

    ll ans=0;

    auto cnt = [&] (ll v) {
        ll a = (choose(v, k/2) * choose(n-v, k/2))%M;
           // b = (choose(v, k/2-1) * choose(n-v-1, k/2))%M;
        deb(a);
        ans = (ans+a)%M;
    };

    function<ll(ll, ll)> dfs = [&] (ll v, ll p) {
        sz[v] = 1;
        for (auto c: adj[v]) if (c != p) {
            sz[v] += dfs(c, v);
            // cnt(sz[c], v);
        }
        // if (v != 1) cnt(sz[v], v);
        return sz[v];
    };

    dfs(1, 0);
    deb(sz);
    FORN(i, 2, n) {
        deb(i, sz[i]);
        cnt(sz[i]);
    }

    ans = (ans*modPow(choose(n, k), M-2) + 1)%M;

    cout<<ans<<"\n";
}

int main() {
    int t=1;
    init();
    // cin >> t;
    while (t--) solve();
}
