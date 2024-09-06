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
    ll n, k;
    cin>>n>>k;

    vll A(n), B(n);
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>B[i];

    vector<pair<ll, ll>> V;
    ll ans = 0;
    REP(i, n) {
        if (B[i]<=A[i]) continue;
        V.eb(A[i], B[i]);
    }
    sort(all(V));
    ll c = 0;
    deb(V);
    multiset<ll> R;
    for (auto [a, b]: V) {
        deb(R, c);
        deb(a, b);
        ans = max(ans, c);
        c -= a;
        if (k==0) {
            c += b;
            continue;
        }
        if (R.size()<k) {
            R.emplace(b);
            continue;
        }
        auto x = *R.begin();
        if (x > b) {
            c += b;
            deb("Wahoo!");
            continue;
        }
        deb("breh", x, a, b);

        c += x;
        R.erase(R.begin());
        R.emplace(b);
    }
    ans = max(ans, c);
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
