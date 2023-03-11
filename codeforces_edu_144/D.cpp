#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 3e5;

ll n, k, x, DP[N][21], A[N];

void solve() {
    cin>>n>>k>>x;
    FORN(i, 1, n) cin>>A[i];

    FORN(i, 0, n) FORN(j, 0, k) DP[i][j] = -INF;
    DP[0][0]=0;
    ll ans = 0;
    FORN(i, 1, n)
        FORN(j, 0, min(i, k)) {
            ll a = j?DP[i-1][j-1]:-INF,
               b = DP[i-1][j];
            DP[i][j] = max({0LL, a+A[i]+x, b+A[i]-x});
            // deb(i, j, a, b, A[i], a+A[i]+x, b+A[i]-x, DP[i][j]);
            if (i+k-j<=n) ans = max(ans, DP[i][j]);
        }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
