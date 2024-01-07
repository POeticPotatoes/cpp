#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;
#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
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

ll n, m;
vll A;
vector<string> S;

string check(ll v) {
    string s;
    REP(i, m) s += ' ';

    REP(i, n) {
        if (i==v) continue;
        REP(j, S[i].size()) {
            ll p = A[i]+j-1;
            if (s[p] != ' ' && s[p] != S[i][j]) return "";
            s[p] = S[i][j];
        }
    }
    REP(i, m) if (s[i] == ' ') return "";
    return s;
}

void solve() {
    cin>>n>>m;
    A = vll(n);
    S = vector<string>(n);
    REP(i, n) cin>>A[i]>>S[i];
    ll cnt=0;
    string ans;

    
    FOR(i, -1, n) {
        auto res = check(i);
        deb(i, res);
        if (res != "") {
            cnt++;
            if (cnt>1 && ans != res)
                return (void) (cout<<"-2\n");
            ans = res;
        }
    }

    if (!cnt) return (void) (cout<<"-1\n");
    return (void) (cout<<ans<<"\n");
}

int main() {
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
