#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
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

const ll N = 505;

ll n, c, A[N], DP[N][N];

ll get(ll a, ll b, ll ofs) { return a>-1 && b>-1 && DP[a][b] != -INF? DP[a][b] + ofs:INF; }

void solve() {
    cin>>n;
    FORN(i, 1, n) cin>>A[i];
    A[n+1] = N;
    DP[0][0] = 0;
    FORN(i, 1, n) DP[0][i] = INF;

    FORN(i, 1, n+1) {
        FORN(j, 0, n) DP[i][j] = INF;
        FOR(k, 0, i) if (A[k] < A[i]) {
            FORN(j, 0, n) {
                DP[i][j] = min(DP[i][j], get(k, j-(i-k>1), i-k-1));
            }
        }
    }
    ll m=DP[n+1][0];
    FORN(i, 1, n) {
        m = min(m, DP[n+1][i]);
        printf("%lld ", m);
    }
    printf("\n");
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
