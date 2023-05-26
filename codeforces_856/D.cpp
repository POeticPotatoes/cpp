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

constexpr int M = 998244353;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 1e4 + 10, H = 1e6;

ll n, A[N], fac[N+1], inv[N+1], P[H]{};

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

ll choose(ll a, ll b) { return ((fac[a]*inv[b])%M * inv[a-b]) %M; }

void init() {
    fac[0] = 1;
    FORN(i, 1, N) fac[i] = (fac[i-1]*i) %M;
    inv[N] = modPow(fac[N], M-2); 
    ROF(i, N, 0) inv[i-1] = (inv[i]*i) %M;
    
    P[1] = 1;
    FOR(i, 2, H) {
        if (P[i]) continue;
        for (int j=i<<1;j<H;j+= i) P[j] = 1;
    }
}

ll inc(int a, int b, int c) { return (((((fac[c+b] * inv[c]) %M) * a) %M) * inv[b]) %M; }

void solve() {
    cin>>n;
    REP(i, n<<1) cin>>A[i];
    map<ll, ll> B;
    REP(i, n<<1) B[A[i]]++;
    vll DP(n+1);
    DP[0] = 1;
    for (auto &[v, c]: B) {
        ROF(i, n, -1) {
            ll j = 0;
            if (!P[v] && i-c+1>=0)
                j = inc(DP[i-c+1], c-1, i-c+1);
            if (i-c >= 0)
                j = (j + inc(DP[i-c], c, i-c)) %M;
            DP[i] = j;
        }
    }
    cout<<DP[n]<<endl;
}

int main() {
    init();
    int t=1;
    while (t--) solve();
}
