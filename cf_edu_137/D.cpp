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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 1e6;

ll n;
string s, ans, t;

string reduce(string &g) {
    REP(i, g.size())
        if (g[i] == '1') return g.substr(i, s.size());
    return "0";
}

string operator | (string &a, string b) {
    string c = string(max(a.size(), b.size()), '0');
    int x=a.size(), y=b.size(), z=c.size();
    FORN(i, 1, a.size())
        c[z-i] = a[x-i] | (y-i>-1?b[y-i]:0);
    deb(a, b, c);
    FOR(i, a.size(), b.size())
        c[z-i] = b[y-i];
    return reduce(c);
}

void solve() {
    cin>>n;
    cin>>s;

    ans = s = reduce(s);
    n = s.size();
    int p = s.find('0');
    if (s.size() == 1 || p == n) return (void) (cout<<s<<endl);

    deb(p);
    FORN(i, 1, p) {
        t = s | s.substr(0, n-i);
        deb(i, t);
        ans = max(ans, t);
    }
    cout<<ans<<endl;
}

int main() {
    int _=1;
    //cin >> t; // Comment this out if there are no tests
    while (_--) solve();
}
