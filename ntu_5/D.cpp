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

const ll N = 4e5;

ll n;
vv<ll> adj;
bool O[N];

bool check(ll v, ll p) {
    ll a = adj[v].size();
    for (auto c: adj[v]) if (c!=p)
        a += check(c, v);
    O[v] = !(a&1);
    return O[v];
}

void dfs(ll v, ll p) {
    vll late;
    for (auto c: adj[v]) if (c != p) {
        if (!O[c]) late.eb(c);
        else dfs(c, v);
    }
    cout<<v<<"\n";
    for (auto c: late) dfs(c, v);
}

void solve() {
    cin>>n;
    adj = vv<ll>(n+1);
    ll c;
    FORN(i, 1, n) {
        cin>>c;
        if (c) {
            adj[i].eb(c);
            adj[c].eb(i);
        }
    }
    if (!check(1, -1)) return (void) (cout<<"NO\n");
    cout<<"YES\n";
    dfs(1, -1);
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
