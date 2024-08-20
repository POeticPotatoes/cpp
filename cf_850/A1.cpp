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
// constexpr int M = 1e9+7;
// constexpr int inf = (int)1e9;
// constexpr ll INF = 1e18;

void solve() {
    ll n;
    cin>>n;
    ll k = (sqrt(8*n+1)+1)/4,
        b = k/2, a=k-b;
    ll x = (8*a-6)*a/2, y = (8*b+2)*b/2, l = n-x-y,
       xb = (x-a)/2, 
       xw = xb+a, 
       yw = (y-b)/2, 
       yb = yw+b;
    if (a==b) {
        xw += (l+1)/2,
        xb += l/2;
    } else {
        yw += l/2;
        yb += (l+1)/2;
    }
    printf("%lld %lld %lld %lld\n", xw, xb, yw, yb);
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
