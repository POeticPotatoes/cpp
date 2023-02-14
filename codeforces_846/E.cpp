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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll l, r, n, c, ans, x;

void solve() {
    cin>>l>>r;
    if ((l-1)*3 <= r) return (cout<<r/2<<endl);
    n = r-l+1;
    ans = max(n, r/2);
    vll X, K;

    c = (n+1)/2;
    while (c < n && c < l) {
        X.eb(x=(l+c-1)/c);
        K.eb(c);
        c = ((r+x-2)/(x-1));
    }
    
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
