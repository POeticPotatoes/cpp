#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 3e6;

ll n, k, m, q, A[N], SUM[N];
set<ll> broke;

ll query(ll a, ll b) {
    if (a>b) swap(a, b);
    deb(a, b, SUM[a-1], SUM[b-1]);
    if (broke.upper_bound(a-1) == broke.upper_bound(b-1)) 
        return SUM[b-1] - SUM[a-1];
    return inf;
}

void solve() {
    cin>>n>>k>>m>>q;
    FORN(i, 1, n) cin>>A[i];
    FORN(i, 1, m+1) cin>>A[n+i];
    FORN(i, 1, n+m+1) SUM[i] = A[i] + SUM[i-1];

    REP(i, q) {
        char c; cin>>c;
        if (c=='q') {
            ll a, b, ans = inf;
            cin>>a>>b;
            if (a>b) swap(a, b);
            if (a<=n && b<=n) {
                ans = min(ans, query(a, b));
                ans = min(ans, query(b, n+1) + query(a, 1));
                ans = min(ans, query(a, 1) + query(b, k) + query(n+1, n+m+2));
                ans = min(ans, query(a, k) + query(b, n+1) + query(n+1, n+m+2));
            } else if (a<=n) {
                deb("woohoo");
                ans = min(ans, query(a, k) + query(b+1, n+m+2));
                deb(ans);
                ans = min(ans, query(a, 1) + query(k, n+1) + query(b+1, n+m+2));
                deb(ans);
                ans = min(ans, query(a, n+1) + query(1, k) + query(b+1, n+m+2));
                deb(ans);
                ans = min(ans, query(a, n+1) + query(b+1, n+1));
                deb(ans);
                ans = min(ans, query(a, 1) + query(b+1, n+1));
                deb(ans);
            } else {
                ans = min(ans, query(a+1, b+1));
                ans = min(ans, query(a+1, n+1) + query(b+1, n+m+2) + query(1, k));
                ans = min(ans, query(a+1, n+1) + query(b+1, n+m+2) + query(k, n+1));
            }
            if (ans>=inf) cout<<"impossible\n";
            else cout<<ans<<"\n";
        } else {
            ll x;cin>>x;
            if (c == 'x') x = n+x+1;
            if (broke.count(x)) broke.erase(x);
            else broke.insert(x);
        }
    }
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
