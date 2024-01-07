#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;
#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
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

void solve() {
    ll n;
    cin>>n;
    vll A(n), B, C;
    REP(i, n) cin>>A[i];

    B.eb(INF);
    C.eb(INF);

    REP(i, n) {
        if (B.back() > C.back()) {
            if (C.back() < A[i] && B.back() >= A[i]) {
                B.eb(A[i]);
                continue;
            }
            C.eb(A[i]);
            continue;
        }
        if (B.back() < A[i] && C.back() >= A[i]) {
            C.eb(A[i]);
            continue;
        }
        B.eb(A[i]);
    }
    deb(B, C);

    ll ans = 0;

    FOR(i, 1, B.size()) {
        ans += B[i]>B[i-1];
    }

    FOR(i, 1, C.size()) {
        ans += C[i]>C[i-1];
    }
    
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
