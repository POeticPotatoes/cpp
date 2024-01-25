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

const ll N = 5000;

ll fac[N+1], inv[N+1];

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
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
    // deb("choose", a, b);
    if (a<b) return 0;
    ll res = ((fac[a]*inv[a-b]) %M * inv[b]) %M;
    return res;
}

void solve() {
    ll n, k;
    cin>>n>>k;
    vll A(n+1);
    FORN(i, 1, n) cin>>A[i];

    vll DP(n+1), CNT(n+1);
    vv<ll> O(n+1);
    CNT[0]=1;

    if (k==1) return (void) (cout<<"1\n");

    FORN(i, 1, n) {
        ll m = 0, c = 0;
        ll sz = O[A[i]].size();

        ROF(j, sz-k+1, -1) {
            ll prev = O[A[i]][j]-1;
            m = max(m, DP[prev]+1);
            // deb(i, prev, m, sz);
            if (DP[prev]+1 < m) break;
            c = ((CNT[prev] * choose(sz-j-1, k-2))%M + c)%M;
        }
        // deb(i, m ,c);

        if (m < DP[i-1]) DP[i] = DP[i-1], CNT[i] = CNT[i-1];
        else if (m > DP[i-1]) DP[i] = m, CNT[i] = c;
        else DP[i] = DP[i-1], CNT[i] = (CNT[i-1] + c)%M;

        O[A[i]].eb(i);
    }
    // deb(DP);
    // deb(CNT);
    cout<<CNT[n]<<"\n";
}

int main() {
    int t=1;
    init();
    cin >> t;
    while (t--) solve();
}
