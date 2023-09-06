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

const ll N = 3000;

ll n, m, k;
pair<ll, ll> A[N];
ll prev = 0;

void solve() {
    cin>>n>>m>>k;
    REP(i, m) cin>>A[i].first>>A[i].second;
    vv<ll> DP(n+1, vll(k+1, -1));
    set<ll> active;
    sort(A, A+m);

    DP[0][0] = 0;
    ll ans = 0;
    REP(i, m) {
        auto &[a, b] = A[i];
        deb(A[i]);
        while (active.size() && *active.begin()<a) {
            FORN(j, 1, k) DP[a-1][j] = max(DP[a-1][j], DP[*active.begin()][j]);
            deb(*active.begin());
            active.erase(active.begin());
        }
        for (auto c: active) {
            FORN(j, 1, k) DP[a-1][j] = max(DP[a-1][j], DP[c][j] - (c-a+1));
            deb(c);
        }
        deb(a-1, DP[a-1]);
        DP[b][0] = 0;
        FORN(j, 1, k) {
            DP[b][j] = max(DP[b][j], DP[a-1][j-1]==-1?-1:DP[a-1][j-1] + b-a+1);
            ans = max(ans, DP[b][j]);
        }
        deb(1, DP[b]);
        active.emplace(b);
        deb(active);
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    FORN(i, 1, t) {
        printf("Case #%lld: ", i);
        solve();
    }
}
