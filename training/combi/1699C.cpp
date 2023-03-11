#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
// #define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
// #define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
// #define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
// #define REP(i, n) FOR(i, 0, n)
// #define all(x) (x).begin(), (x).end()
// #define eb emplace_back
typedef long long ll;
// typedef long double ld;
// typedef vector<ll> vll;
// template <typename T>
// using vv = vector<vector<T>>;
// template <typename T>
// using vvv = vector<vv<T>>;
// template <typename T, typename N>
// using um = unordered_map<T, N>;
// template <typename T>
// using MinHeap = priority_queue<T, vector<T>, greater<T>>;
// template <typename T>
// using MaxHeap = priority_queue<T>;
// 
constexpr int M = 1e9+7;
// constexpr int inf = (int)1e9;
// constexpr ll INF = 1e18;

const ll N = 2e5;

ll n, A[N], B[N], fac[N], inv[N];

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

void solve() {
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>A[i];
        B[A[i]] = i;
    }

    fac[0] = 1;
    for (int i=1;i<=n;i++) fac[i] = (fac[i-1]*i) %M;
    inv[n] = modPow(fac[n], M-2);
    for (int i=n;i>0;i--) inv[i-1] = (inv[i]*i) %M;

    ll ans = 1, fixed = 1, l=B[0], r=B[0];
    for (int i=1;i<n;) {
        while (i<n && (B[i]<l || B[i]>r)) {
            l = min(l, B[i]);
            r = max(r, B[i]);
            fixed++, i++;
        }
        if (i==n) break;
        deb(i, l, r, fixed, r-l+1-fixed);
        ll c=0, s=r-l+1-fixed;
        while (i<n && B[i]>l && B[i]<r) i++, c++;
        ans = ((fac[s]*inv[s-c])%M * ans) %M;
        fixed += c;
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
