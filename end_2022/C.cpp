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
constexpr ll N = 100;

ll n, A[N], C[N], cur;
bool flag;

bool check(ll k) {
    memset(C, 0, sizeof(C));
    REP(i, n) C[A[i]%k]++;
    return (*min_element(C, C+k))<2;
}

void solve() {
    cin>>n;
    set<ll> vis;
    flag = 0;
    REP(i, n) {
        cin>>A[i];
        if (vis.count(A[i])) {
            flag = 1;
            continue;
        }
        vis.insert(A[i]);
    }
    if (flag) return (void) (cout<<"NO"<<endl);
    for (int i=2;i<=n/2;i++)
        if (!check(i)) return (void) (cout<<"NO"<<endl);
    cout<<"YES"<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
