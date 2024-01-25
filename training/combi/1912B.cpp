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
const int M = MOD[3];
const int inf = (int)1e9;
const ll INF = 1e18;

const ll N = 2e5;

ll fac[N+1], inv[N+1];

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

ll choose(ll a, ll b) {
    // deb(a,b);
    if (a<0 || b<0 || b>a) return 0;
    return ((fac[a]*inv[a-b])%M * inv[b])%M;
}

void solve() {
    ll n, k;
    cin>>n>>k;
    ll t = k*2;
    ll sz = n/t, rem = n%t, cnt=0;
    // deb(n, k, sz, rem, rem-k+1);
    if (sz == 0) {
        cnt = choose(k-1, rem-k-1);
    } else if (rem) FORN(i, rem - min(rem/2, k-1), rem) {
        // deb(i);
        cnt = (cnt + (choose(k-1, i) * choose(i, i-(rem-i))%M))%M;
        if (i-(rem-i)>0) cnt = (cnt + 2*((choose(k-1, i-1) * choose(i-1,rem-i))%M))%M;
        if (i-(rem-i)>1) cnt = (cnt + ((choose(k-1, i-2) * choose(i-2, rem-i))%M))%M;
    } else cnt=1;
    ll ans = sz*(sz-1)/2* t + sz*rem;
    cout<<ans<<" "<<cnt<<"\n";
}

void init() {
    fac[0] = 1;
    FORN(i, 1, N) fac[i] = (fac[i-1]*i) %M;
    inv[N] = modPow(fac[N], M-2);
    ROF(i, N, 0) inv[i-1] = (inv[i]*i) %M;
}

int main() {
    int t=1;
    init();
    cin >> t;
    while (t--) solve();
}
