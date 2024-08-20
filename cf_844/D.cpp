#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
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
constexpr ll N = 100;

ll n, A[N], ans;
map<ll, ll> X;

void check(ll n1, ll n2) {
    ll a=A[n1], b=A[n2], d=b-a, m=sqrt(d);
    FORN(i, 1, m) {
        if (d%i) continue;
        ll p = i, q = d/i;
        if ((p&1) == (q&1)) {
            ll v = (p+q)/2, x=v*v-b;
            if (x>=0) {
                deb(a, b, x);
                X[x] |= (1LL<<n1) | (1LL<<n2);
            }
        }
    }
}

void solve() {
    X.clear();
    cin>>n;
    sort(A, A+n);
    REP(i, n) cin>>A[i];
    REP(a, n) FOR(b, a+1, n) check(a, b);
    ans=1;
    for (auto p: X) ans=max(ans, (ll) __builtin_popcountll(p.second));
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
