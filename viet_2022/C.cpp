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

ll n, A[N], V[N], J[N], P[N], z;

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>A[i+n];

    vll ans;
    REP(i, n<<1) if (!A[i]) {
        z = i;
        break;
    }
    ll o = n - (z%n) -1, m = n>>1<<1;
    if (z<n) REP(i, n<<1) {
        J[(i+o)%n] = V[(i+o)%n] = A[i];
        P[A[i]] = (i+o)%n;
        J[(i+o)%n + n] = V[(i+o)%n + n] = A[i+n];
        P[A[i+n]] = (i+o)%n + n;
    } else REP(i, n<<1) {
        J[(i+o)%n+n] = V[(i+o)%n+n] = A[i];
        P[A[i]] = (i+o)%n+n;
        J[(i+o)%n] = V[(i+o)%n] = A[i+n];
        P[A[i+n]] = (i+o)%n;
    }
    z = (n<<1) - 1;

    REP(i, m) {
        // move V[i+n] to V[i]
        ans.eb(V[i]);
        swap(P[V[i] 
    }
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
