#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll n;

string s, v = "spbsu";

void solve() {
    cin>>n;
    cin>>s;
    vv<ll> LEF(n+2, vll(5, -INF)), RIG(n+2, vll(5, INF));
    FORN(i, 1, n) REP(j, 5)
        LEF[i][j] = s[i-1]==v[j]?i:LEF[i-1][j];
    ROF(i, n, 0) REP(j, 5)
        RIG[i][j] = s[i-1]==v[j]?i:RIG[i+1][j];
    ll ans = INF;
    deb(LEF, RIG);
    REP(j, 5) {
        FORN(i, 1, n) {
            if (s[i-1] != v[j]) continue;
            ll p = i;
            ll res = 0;
            bool flag=false;
            ROF(k, j-1, -1) {
                res += i-j+k-LEF[p][k];
                p = LEF[p][k];
                if (p==-INF) {
                    flag = true;
                    break;
                }
            }
            deb(i, j, p, res, flag);
            if (flag) break;
            p = i;
            FOR(k, j+1, 5) {
                res += RIG[p][k]-(i-j+k);
                p = RIG[p][k];
                if (p==INF) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            ans = min(ans, res);
            deb(j, i, res);
        }
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
