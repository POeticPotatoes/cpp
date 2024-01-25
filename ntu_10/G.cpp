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

void solve() {
    ll n, k;
    cin>>n>>k;
    ll x = log2(k)+1, m = 0;
    vll A(n);
    REP(i, n) cin>>A[i];
    sort(all(A));
    REP(i, x) m += A[i];
    map<ll, ll> DP;
    DP[0]=1;
    deb(x, m);

    REP(i, x) {
        map<ll, ll> K=DP;
        for (auto p = DP.rbegin();p!=DP.rend();p++) {
            K[p->first + A[i]]+=p->second;
        }
        DP=K;
    }

    for (auto p = next(DP.begin());p!=DP.end();p++)
        p->second += prev(p)->second;
    deb(DP);

    auto check = [&](ll v) {
        ll ans = prev(DP.upper_bound(v))->second;
        FOR(i, x, n) {
            if (A[i] > v) break;
            ans += prev(DP.upper_bound(v-A[i]))->second;
        }
        return ans;
    };

    ll l=0, r=m;
    while (l<r) {
        deb(l, r);
        ll mid = (l+r)>>1;
        if (check(mid) > k) r = mid;
        else l = mid+1;
    }
    cout<<l<<"\n";
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
