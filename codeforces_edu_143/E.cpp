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

const ll N = 4e5;

ll n, A[N], L[N], R[N];

void DP(ll *B) {
    stack<pair<ll, ll>> s;
    for (int i=1;i<=n;i++) {
        ll h = A[i], v = h-i;
        while (s.size() && (s.top().second <= i-h || s.top().first >= v)) s.pop();
        ll j = s.empty()?max(0LL, i-h):s.top().second,
           d = i-j;
        B[i] = (2*h-d+1)*d/2;
        if (s.size()) B[i] += B[j];
        // deb(i, h, j, d, (2*h-d+1)*d/2, B[i]);
        s.push({h-i, i});
    }
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>A[i];
    ll s = 0;
    for (int i=1;i<=n;i++) s+= A[i];
    DP(L);
    reverse(A+1, A+n+1);
    DP(R);

    ll ans=1e18;
    for (int i=1;i<=n;i++) {
        ans = min(ans, s-R[i]-L[n+1-i]+2*A[i]);
        // deb(s, n+1-i, R[i], L[n+1-i], A[i], ans);
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
