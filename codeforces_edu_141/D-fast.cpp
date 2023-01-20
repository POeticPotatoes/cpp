#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
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

constexpr int MOD = 998244353;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N=500, M=1e5;

ll n, A[N], DP[2][2*M]{}, *p, b, v, ans, x, m;

void solve() {
    scanf("%lld", &n);
    for (int i=1;i<=n;i++) scanf("%lld", A+i);
    x=1;
    DP[0][A[2]+M]++;
    for (int i=2;i<=n-1;i++) {
        memset(DP[x], 0, sizeof(DP[x]));
        b = A[i+1], m = 2*M-b;
        // printf("B: %lld\n", b);
        for (int a=0;a<m;a++) {
            v = DP[x^1][a];
            if (v) {
                // printf("Position: %lld Value: %lld Count: %lld (%lld, %lld)\n", i, a-M, v, b+a-M, b-a+M);
                DP[x][b+a] = (DP[x][b+a]+v)%MOD;
                if (a!=M) {
                    DP[x][b-a+2*M] = (DP[x][b-a+2*M]+v)%MOD;
                }
            }
        }
        x ^=1;
    }
    x^=1;
    ans=0;
    for (int i=0;i<2*M;i++) {
        // if (DP[x][i]) printf("Value: %lld Count: %lld\n", i-M, DP[x][i]);
        ans = (ans+DP[x][i])%MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
