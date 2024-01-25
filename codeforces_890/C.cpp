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

const ll N = 2e3;

ll n, k, A[N], ans;
pair<ll, ll> DP[N][N];

void solve() {
    cin>>n>>k;
    REP(i, n) cin>>A[i];
    A[n] = A[n-1]-1, ans=0;
    ROF(i, n-1, -1) {
        DP[i][i] = {A[i], k};
        ans = max(ans, min(A[i] + k, A[i+1]+1));
        FOR(j, i+1, n) {
            if (DP[i+1][j].first != -1) {
                ll d=INF;
                if (A[i] > DP[i+1][j].first + 1) {
                    if (A[i]-A[j]-(j-i) <= A[j+1]-A[j]+1)
                        d = (A[i]-DP[i+1][j].first-1) * (j-i);
                }
                else d = DP[i+1][j].first + 1 - A[i];
                if (d <= DP[i+1][j].second) {
                    DP[i][j] = {max(A[i], DP[i+1][j].first+1), DP[i+1][j].second - d};
                    ll lim = max(0LL, A[j+1]+1 - DP[i][j].first + (j-i));
                    ans = max(ans, DP[i][j].first + min(lim, DP[i][j].second/(j-i+1)));
                    continue;
                } 
            } 
            DP[i][j] = {-1, -1};
        }
    }
    // REP(j, n) {
    //     REP(i, n) printf("(%2lld, %2lld) ", DP[i][j].first, DP[i][j].second);
    //     printf("\n");
    // }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
