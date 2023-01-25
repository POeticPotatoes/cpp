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

constexpr ll N = 2e5;

ll n, A[N], l, r, m, c, k;

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];
    
    if (n==1) return (void) (cout<<0<<endl);
    k = (n+1)/2;
    for (m=0;A[m] != k; m++);
    l = r = 0;
    c = k;
    ROF(i, m, -1) {
        if (A[i] == c) {
            c--;
            continue;
        }
        A[i] < k? l++:r++;
        deb(i, A[i], l, r, c);
    }
    c = k;
    FOR(i, m, n) {
        if (A[i] == c) {
            c++;
            continue;
        }
        A[i] < k? l++:r++;
        deb(i, A[i], l, r, c);
    }
    deb(l, r);
    cout<<max(l, r)<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
