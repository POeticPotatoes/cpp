#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
// #define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
// #define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
// #define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
// #define REP(i, n) FOR(i, 0, n)
// #define all(x) (x).begin(), (x).end()
// #define eb emplace_back
typedef long long ll;
// typedef long double ld;
// typedef vector<ll> vll;
// template <typename T>
// using vv = vector<vector<T>>;
// template <typename T>
// using vvv = vector<vv<T>>;
// template <typename T, typename N>
// using um = unordered_map<T, N>;
// template <typename T>
// using MinHeap = priority_queue<T, vector<T>, greater<T>>;
// template <typename T>
// using MaxHeap = priority_queue<T>;
// 
// constexpr int M = 1e9+7;
// constexpr int inf = (int)1e9;
// constexpr ll INF = 1e18;

const ll N = 2e5+10;

ll n, m, A[N], C[2*N];

void solve() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>A[i];
    memset(C, 0, sizeof(ll)*(n+m+1));
    for (int i=1;i<=n;i++) C[A[i]] = m+1;
    for (int i=0;i<m;i++) {
        ll p, v;
        cin>>p>>v;
        C[A[p]] -= m-i;
        C[v] += m-i;
        A[p] = v;
    }
    ll s = m*(m+1)/2, ans=0;
    for (int i=0;i<=n+m;i++) {
        ll j = m-C[i];
        ans += s - j*(j+1)/2;
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
