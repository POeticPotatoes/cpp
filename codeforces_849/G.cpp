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

const ll N=3e5;

ll n, c, A[N], vis[N];

void solve() {
    cin>>n>>c;
    for(ll i=1;i<=n;i++) cin>>A[i];
    memset(vis, 0, sizeof(ll)*n);
    vector<ll> P(n+1), S(n+1);
    for(ll i=1;i<=n;i++)
        P[i] = (min(i, n-i+1) + A[i]);
    sort(P.begin(), P.end());
    for(ll i=1;i<=n;i++) S[i] = S[i-1] + P[i];
    // deb(P, S);

    ll ans = 0;
    for(ll i=1;i<=n;i++) {
        ll v = A[i]+i, s = min(i, n-i+1) + A[i];
        if (c<v) continue;
        ll p = upper_bound(S.begin(), S.end(), c-v) - S.begin();
        // deb(i, v, P[i], p);
        if (p<=n && P[p] > s) {
            p = upper_bound(S.begin(), S.end(), c-v+s) - S.begin() - 1;
            // deb(1);
        }
        if (p>n) p=n;
        // deb(p);
        ans = max(ans, p);
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
