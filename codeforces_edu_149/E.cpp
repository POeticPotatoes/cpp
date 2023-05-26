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
const int M = MOD[3];
const int inf = (int)1e9;
const ll INF = 1e18;

const ll N = 6e5;

ll k, A[N], ans=1, fac[N];
vll C(20);

ll dfs(ll l, ll r, ll lvl) {
    if (l==r) return A[l]==-1?INF:A[l]==1?0:log2(A[l]-1)+1;
    ll m = (l+r)>>1, a = dfs(l, m, lvl+1), b = dfs(m+1, r, lvl+1);
    if ((a<lvl && b<lvl) || (a==lvl && b==lvl)) ans = 0;
    ans = (ans * (1 + (a>lvl && b>lvl))) %M;
    return min(a, b);
}

void solve() {
    cin>>k;
    FORN(i, 1, 1<<k) {
        cin>>A[i];
        if (A[i]>0) C[(int) (A[i]==1?0:log2(A[i]-1)+1)]++;
    }
    dfs(1, 1<<k, 1);
    FORN(i, 1, k) ans = (ans * fac[(1<<(i-1)) - C[i]]) %M;
    cout<<ans<<endl;
}

int main() {
    int t=1;
    fac[0] = 1;
    FOR(i, 1, N) fac[i] = (fac[i-1] * i) %M;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
