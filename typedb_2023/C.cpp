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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 3e5;

ll n, s, A[N], DP[N][2], V[N][2];

void check(ll k) {
    ll a, v=A[k];
    if (v<2*s) a = min(v, s);
    else a = s;
    V[k][0] = a;
    V[k][1] = v-a;
}

void solve() {
    cin>>n>>s;
    REP(i, n) cin>>A[i];

    FOR(i, 1, n-1) check(i);
    V[n-1][0] = V[n-1][1] = A[n-1];
    V[0][0] = V[0][1] = A[0];
    DP[0][0] = DP[0][1] = 0;

    FOR(i, 1, n) {
        DP[i][0] = min((V[i][0]*V[i-1][1] + DP[i-1][0]),
                      (V[i][0]*V[i-1][0] + DP[i-1][1]));
        DP[i][1] = min((V[i][1]*V[i-1][1] + DP[i-1][0]),
                      (V[i][1]*V[i-1][0] + DP[i-1][1]));
    }
    cout<<min(DP[n-1][0], DP[n-1][1])<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
