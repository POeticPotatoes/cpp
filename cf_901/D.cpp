<<<<<<< Updated upstream
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
=======
#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;
#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
>>>>>>> Stashed changes
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
    ll n;
    cin>>n;
    vll A(n+1);
    REP(i, n) {
        ll c;
        cin>>c;
<<<<<<< Updated upstream
        A[c]++;
    }
    ll m = 0; while (A[m]) m++;
    deb(A, m);
    if (!m) return (void) (cout<<"0\n");
    vv<ll> DP(m, vll(n));
    REP(i, n) DP[0][i] = m * min(i, A[0]);

    FOR(i, 1, m) {
        REP(j, A[i]) DP[i][j] = DP[i-1][j];
        FOR(j, A[i], n) {
            DP[i][j] = min(DP[i-1][j], m*A[i] + DP[i-1][j-A[i]]);
        }
    }
    deb(DP);
    cout<<DP[m-1][n-1]<<"\n";
=======
        if (c<=n) A[c]++;
    }

    ll m = 0; while (A[m]) m++;

    vll DP(m+1, inf);
    DP[0] = 0;

    FORN(i, 1, m) {
        ROF(j, i-1, -1) {
            DP[i] = min(DP[i], DP[j]+j+(A[j]-1)*i);
        }
    }
    cout<<DP[m]<<"\n";
>>>>>>> Stashed changes
}

int main() {
    int t=1;
<<<<<<< Updated upstream
    cin >> t;
=======
    cin >> t; // Comment this out if there are no tests
>>>>>>> Stashed changes
    while (t--) solve();
}
