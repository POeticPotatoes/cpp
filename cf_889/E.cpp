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

const ll N = 600;

ll n, m, A[N], DP[N][N];

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans)%M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

ll divid(ll a, ll b) { return a*modPow(b, M-2); }

void solve() {
    cin>>n>>m;
    REP(i, n) cin>>A[i];
    A[n] = m+1;

    FORN(i, 1, m+1) DP[i][m+1] = m+1-i;
    ROF(j, m, 0) {
        DP[j][j] = 0;
        ROF(i, j-1, 0) DP[i][j] = divid((DP[i][j+1] + DP[i+1][j])%M + 1, 2);
    }

    ll ans = 0;
    REP(i, n) ans = (ans + DP[A[i]][A[i+1]]) %M;
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
