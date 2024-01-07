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
    ll n,m ;
    cin>>n>>m;
    vector<string> A(n);
    vv<char> ans(n, vector<char>(m, '.'));
    REP(i, n) cin>>A[i];

    vv<ll> p(n);
    REP(i, n) REP(j, m) if (A[i][j]=='U') p[i].eb(j);
    REP(i, n) {
        if (p[i].size()&1) return (void) (cout<<"-1\n");
        ll k = p[i].size();
        REP(j, k>>1) {
            ans[i][p[i][j]] = 'W';
            ans[i+1][p[i][j]] = 'B';
        }
        FOR(j, k>>1, k) {
            ans[i][p[i][j]] = 'B';
            ans[i+1][p[i][j]] = 'W';
        }
    }
    p = vv<ll>(m);
    REP(j, m) REP(i, n) if (A[i][j]=='L') p[j].eb(i);
    REP(j, m) {
        if (p[j].size()&1) return (void) (cout<<"-1\n");
        ll k = p[j].size();
        REP(i, k>>1) {
            ans[p[j][i]][j] = 'W';
            ans[p[j][i]][j+1] = 'B';
        }
        FOR(i, k>>1, k) {
            ans[p[j][i]][j] = 'B';
            ans[p[j][i]][j+1] = 'W';
        }
    }
    REP(i, n) {
        REP(j, m) cout<<ans[i][j];
        cout<<"\n";
    }
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
