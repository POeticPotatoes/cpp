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
constexpr ll N = 2e5;

ll n, k, vis[N], r, minPow, minHealth;
pair<ll, ll> H[N], P[N];

void solve() {
    cin>>n>>k;
    REP(i, n) cin>>H[i].first;
    REP(i, n) cin>>P[i].first;
    REP(i, n) H[i].second = P[i].second = i;
    memset(vis, 0, sizeof(vis));

    sort(H, H+n); sort(P, P+n);
    r = minPow = minHealth = 0;
    while (minHealth < n) {
        if (H[minHealth].first-r <= 0) {
            vis[H[minHealth].second] = 1;
            minHealth++;
            continue;
        }
        while (vis[P[minPow].second]) minPow++;
        ll p = P[minPow].first, req = k/p;
        if (k*(req+1) - ((p*req*req)/2) < H[minHealth].first-r)
            return (void) (cout<<"NO"<<endl);
    }
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
