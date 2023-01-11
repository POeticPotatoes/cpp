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

constexpr ll MOD = 998244353;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 1e5+1;

ll n, ans, A[N], B[N], vis[N], avail[N];
vv<ll> edges;

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>B[i];
    ans = 1;
    edges = vv<ll>(n+1);
    REP(i, n) {
        if (A[i] == B[i]) {
            if (vis[A[i]]++) return (void) (cout<<0<<endl);
            ans = (ans*n)%MOD;
            continue;
        }
        avail[A[i]]++;
        avail[B[i]]++;
    }
    FOR(i, 1, n+1) {
        if (vis[i]) continue;
    }
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
