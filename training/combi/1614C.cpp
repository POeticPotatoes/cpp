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
constexpr int M = 1e9+7;
// constexpr int inf = (int)1e9;
// constexpr ll INF = 1e18;

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans)%M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

void solve() {
    int n, m, l, r, c;
    ll v=0;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>l>>r>>c;
        v |= c;
    }
    ll ans = modPow(2, n-1);
    ans = (ans * v) %M;
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
