#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll i = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 1, n)
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
constexpr ll N = 500;

ll n, A[N], ans, a, b;
map<ll, ll> DP[N];

void increase (ll i, ll y, ll v) {
    ll &k = DP[i][y];
    k = (k+v)%MOD;
}

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];

    DP[0][A[2]]++;
    REP(i, n-2) {
        b=A[i+2];
        cout<<"B: "<<b<<endl;
        for (auto p: DP[i-1]) {
            a = p.first;
            printf("Position: %lld Value: %lld Count: %lld (%lld, %lld))\n", i+1, p.first, p.second, b+a, b-a);
            increase(i, b+a, p.second);
            if (a) increase(i, b-a, p.second);
        }
    }
    ll s=0;
    for (auto p: DP[n-2]) {
        printf("Value: %lld Count: %lld\n", p.first, p.second);
        s = (s+p.second)%MOD;
    }
    cout<<s<<endl;
}

int main() {
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
