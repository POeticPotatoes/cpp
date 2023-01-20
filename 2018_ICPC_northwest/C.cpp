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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 2000;
constexpr ld PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164;

ll n, a, b, vis[N], S[N];
pair<ld, ld> ans[N];
vll edges[N];

void allocate(ll k, ld l, ld r) {
    vis[k] = 1;
    auto p = ans[k];
    ld o = r-l, ng, f, t=S[k]-1;
    for (auto i:edges[k]) {
        if (vis[i]) continue;
        ng = o * S[i]/t;
        // printf("Angle for %lld: %Lf (r: %Lf l: %Lf o: %Lf)\n", i, ng, r, l, o);
        f = l+ng/2;
        ans[i] = {p.first+sin(f), p.second+cos(f)};
        allocate(i, l, l+ng);
        l += ng;
    }
}

ll check(ll k) {
    vis[k] = 1;
    S[k]=1;
    for (auto i: edges[k]) {
        if (vis[i]) continue;
        S[k] += check(i);
    }
    // printf("Node %lld has %lld children.\n", k, S[k]-1);
    return S[k];
}

void solve() {
    scanf("%lld", &n);
    FOR(i, 1, n) {
        scanf("%lld %lld", &a, &b);
        edges[a].eb(b);
        edges[b].eb(a);
    }
    check(1);
    memset(vis, 0, sizeof(vis));
    allocate(1, 0, 2*PI);
    for(int i=1;i<=n;i++)
        printf("%.7Lf %.7Lf\n", ans[i].first, ans[i].second);
}

int main() {
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
