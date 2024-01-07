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

ll n;

void solve() {
    cin>>n;
    vector<string> S(n);
    vv<ll> DP(n, vll(n)), LEF(n, vll(n)), RIG(n, vll(n));
    REP(i, n) cin>>S[i];
    ll ans = 0;

    REP(i, n) REP(j, n) {
        if (i) {
            DP[i][j]+=DP[i-1][j];
            if (j) {
                DP[i][j]+=RIG[i-1][j-1];
                RIG[i][j]+=RIG[i-1][j-1];
            }
            if (j<n-1) {
                DP[i][j]+=LEF[i-1][j+1];
                LEF[i][j]+=LEF[i-1][j+1];
            }
        }
        ll d = (S[i][j]-'0')^(DP[i][j]&1);
        DP[i][j]+=d;
        LEF[i][j]+=d;
        RIG[i][j]+=d;
        ans+=d;
    }
    cout<<ans<<"\n";
}

int main() {
    IO;
    int t=1;
    cin >> t;
    while (t--) solve();
}
