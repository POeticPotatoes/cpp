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
    ans = (ans *ans) %M;
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
    deb("choose", a, b);
    ll res = ((fac[a] * inv[a-b])%M * inv[b])%M;
    return res;
}

void solve() {
    ll n, k;
    cin>>n>>k;

    vv<ll> adj(n+1);
    vll DP(n+1), sz(n+1);

    REP(i, n-1) {
        ll a, b;
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    if (k==1 || k==3) return (void) (cout<<"1\n");

    ll sum=0;
    function<ll(ll, ll)> dfs = [&] (ll v, ll p) {
        sz[v]=1;
        for (auto c: adj[v]) if (c != p) {
            dfs(c, v);
            DP[v] = (DP[v] + DP[c])%M;
            sz[v] += sz[c];
        }

        DP[v] = (DP[v] + sz[v]) %M;
        return sz[v];
    };

    function<void(ll, ll, ll, ll)> dfs2 = [&] (ll v, ll p, ll c, ll val) {
        sz[v] += c;
        DP[v] = ((DP[v] + val) %M + c)%M;
        sum = (sum+DP[v]) %M;

        for (auto ch: adj[v]) if (ch != p) {
            dfs2(ch, v, sz[v]-sz[ch], DP[v]-DP[ch]-sz[ch]);
        }
    };

    dfs(1, -1);
    deb(DP, sum);
    dfs2(1, -1, 0, 0);
    deb(DP, sum);

    sum = (((sum-n+M)%M) * modPow(2, M-2))%M;
    deb(sum);

    ll ans = (sum * modPow(choose(n, 2), M-2))%M;
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    init();
    // cin >> t;
    while (t--) solve();
}
