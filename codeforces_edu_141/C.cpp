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
constexpr ll N = 6e5;

ll n, m, A[N], c, s, last, p;

void solve() {
    scanf("%lld", &n);
    scanf("%lld", &m);
    REP(i, n) scanf("%lld", A+i);

    MinHeap<pair<ll, ll>> q;
    REP(i, n) q.push({A[i], n-i});
    c=0, s=0, last=0;
    while (q.size() && m-s>=q.top().first) {
        s += q.top().first;
        last = n-q.top().second;
        q.pop();
        c++;
    }
    if (c&&c<n) {
        s += A[c] - A[last];
        c += s<=m;
    }
    printf("%lld\n",n-c+1);
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
