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
constexpr ll N = 3e5;

ll n, A[N], ans, c, d;
char s[N];

void solve() {
    cin>>n;
    cin>>(s+1);
    FORN(i, 1, n) cin>>A[i];
    ans = 0, d = 0, c = inf;
    ROF(i, n, -1) {
        if (s[i] == '1') {
            d += A[i];
            if (c > A[i]) c=A[i];
        } else {
            if (d)
                ans += max(d, d-c+A[i]);
            d = 0;
            c = inf;
        }
        deb(i, c, d, ans);
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    s[0] = 0;
    A[0] = -1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
