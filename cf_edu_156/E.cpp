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

void solve() {
    ll n, m;
    cin>>n>>m;
    vll A(n), B(m), O(n+1);
    vv<ll> DP(n, vll(m, inf)), ans(m);
    vll ANS(1<<m, inf);
    ANS[0] = 0;
    REP(i, n) cin>>A[i];
    REP(i, m) cin>>B[i];
    iota(all(O), 0);
    sort(next(O.begin()), O.end(), [&] (ll a, ll b) {
            return A[a-1] < A[b-1];
        });
    sort(all(A));
    deb(O, A);
    REP(i, n) {
        REP(j, m) {
            if (i) DP[i][j] = min(DP[i][j], DP[i-1][j]);
            ll p = (B[j]-1)/A[i];
            if (i+p < n) DP[i+p][j] = p+1;
        }
    }
    deb(A, B);
    deb(DP);
    FOR(i, 1, 1<<m) { 
        REP(j, m) if (i>>j&1) {
            if (ANS[1<<j^i] < n) ANS[i] = min(ANS[i], ANS[1<<j^i] + DP[n-1-ANS[1<<j^i]][j]);
        }
    }
    deb(ANS);
    if (ANS[(1<<m)-1] >= inf) return (void) (cout<<"NO\n");

    ll k = (1<<m)-1, p = n-ANS[(1<<m)-1];
    while (k) {
        REP(i, m) if (k>>i&1) {
            ll v = (B[i]-1)/A[p];
            if (p + v == n-1-ANS[1<<i^k]) {
                FORN(j, 0, v) ans[i].eb(p+j);
                k^=1<<i, p += v+1;
                break;
            }
        }
    }
    cout<<"YES\n";
    REP(i, m) {
        cout<<ans[i].size();
        for (auto c: ans[i]) cout<<" "<<O[c+1];
        cout<<"\n";
    }
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
