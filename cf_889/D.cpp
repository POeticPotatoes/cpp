#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll i = (a); (i) > (b); (i)--)
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

const ll MOD[] = {999727999, 1070777777, 1000000007, 998244353};
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
const int M = MOD[2];
const int inf = (int)1e9;
const ll INF = 1e18;

const ll N = 1e5 + 10;
ll n, A[N], S[N];

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];
    if (n==1) return (void) (cout<<A[0]);
    bitset<N> DP;
    DP[0] = 1;
    S[0] = A[0];
    FOR(i, 1, n) S[i] = S[i-1] + A[i]-1;
    
    ll ans=0;
    REP(i, n) {
        deb(S[i]);
    }
    REP(i, n) {
        ll p = DP._Find_next(max(i-1, n-A[i]-2));
        if (p < N) ans = max(ans, S[n-1]+n-1 - (p+A[i]));
        deb(i, p, S[n-1]+n-1, p+A[i]+1, ans);
        DP |= (DP & (bitset<N>().flip()<<i))<<A[i];
    }
    REP(i, n) if (DP[i])
        ans = max(ans, S[i]);
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
