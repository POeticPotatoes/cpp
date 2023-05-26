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

const ll N = 4e5;

ll n, A[N], ans[N], DP[N], MX[N], F[N];

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];
    MX[n] = 0, DP[n] = 0, F[n] = 0;
    ROF(i, n-1, 0) {
        DP[i] = (i+A[i]+1 > n || DP[i+A[i]+1] == -1)?-1:DP[i+A[i]+1]+1;
        MX[i] = max(MX[i+1], DP[i+1]);
        F[i] = max(i+A[i]+1>n?-1:F[i+A[i]+1] + 1, MX[i] + 1);

        if (DP[i] == A[i-1]) ans[i-1] = 0;
        else if (DP[i]>-1 || A[i-1] <= F[i]) ans[i-1] = 1;
        else ans[i-1] = 2;
        deb(A[i], DP[i], MX[i], F[i]);
    }
    REP(i, n-1) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
