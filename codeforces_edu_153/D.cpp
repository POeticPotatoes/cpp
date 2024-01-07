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

const ll N = 100, K = 5000;

string s;

void solve() {
    cin>>s;
    ll n = s.size(),
       z = count(all(s), '0'),
       m = z*(n-z)/2;

    vvv<ll> DP(n+1, vv<ll>(n+1, vll(m+1, INF)));
    DP[0][0][0] = s[0] == '0';
    DP[0][1][0] = s[0] == '1';

    REP(i, n-1) FORN(j, 0, n) FORN(k, 0, m) {
        if (k+j<=m) DP[i+1][j][k+j] = min(DP[i+1][j][k+j], DP[i][j][k] + (s[i+1] == '0'));
        if (j+1<=n) DP[i+1][j+1][k] = min(DP[i+1][j+1][k], DP[i][j][k] + (s[i+1] == '1'));
    }
    cout<<DP[n-1][z][z*(n-z)/2]/2<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
