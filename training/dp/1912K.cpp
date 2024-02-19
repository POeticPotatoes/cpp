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
const int M = MOD[3];
const int inf = (int)1e9;
const ll INF = 1e18;

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

void solve() {
    ll n;
    cin>>n;

    vll A(n+1);
    FORN(i, 1, n) cin>>A[i];

    vvv<ll> DP(n+1, vv<ll>(3, vll(5)));

    ll o=0;
    FORN(i, 1, n) {
        o += A[i]&1;

        REP(j, 3) REP(k, 5) DP[i][j][k] = DP[i-1][j][k];

        if (A[i]&1) {
            DP[i][0][0]++;
            DP[i][0][1] = (DP[i][0][1] + DP[i-1][0][0]) %M;
            DP[i][0][3] = (DP[i][0][3] + DP[i-1][0][2]) %M;
            DP[i][0][4] = (DP[i][0][4] + DP[i-1][0][3]) %M;

            DP[i][1][0]++;
            DP[i][1][2] = (DP[i][1][2] + DP[i-1][1][1]) %M;
            DP[i][1][3] = (DP[i][1][3] + DP[i-1][1][2]) %M;
            DP[i][1][2] = (DP[i][1][2] + DP[i-1][1][4]) %M;

            DP[i][2][1] = (DP[i][2][1] + DP[i-1][2][0]) %M;
            DP[i][2][2] = (DP[i][2][2] + DP[i-1][2][1]) %M;
            DP[i][2][4] = (DP[i][2][4] + DP[i-1][2][3]) %M;
            DP[i][2][2] = (DP[i][2][2] + DP[i-1][2][4]) %M;
        } else {
            DP[i][0][2] = (DP[i][0][2] + DP[i-1][0][1]) %M;
            DP[i][0][2] = (DP[i][0][2] + DP[i-1][0][4]) %M;

            DP[i][1][1] = (DP[i][1][1] + DP[i-1][1][0]) %M;
            DP[i][1][4] = (DP[i][1][4] + DP[i-1][1][3]) %M;

            DP[i][2][0]++;
            DP[i][2][3] = (DP[i][2][3] + DP[i-1][2][2]) %M;
        }
    }
    ll ans=0;
    REP(j, 3) FOR(k, 2, 5) ans = (ans + DP[n][j][k]) %M;

    ll e = n-o;
    if (e>2) {
        ll t = modPow(2, e);
        t = (t - 1 - e + M) %M;
        t = ((t - ((e*(e-1))/2))%M + M) %M;
        deb(e, t, ans);
        ans = (ans + t) %M;
    }


    cout<<ans<<"\n";

    deb(DP);
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
