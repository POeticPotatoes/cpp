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

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;

    vv<ll> vis(50, vll(50));

    set<pair<ll, ll>> F, P;
    function<void(ll, ll, ll)> dfs = [&](ll p, ll x, ll y) {
        if (p==n) {
            deb(x, y);
            F.emplace(x, y);
            return;
        }
        bool flag = vis[x][y];
        vis[x][y] = 1;
        pair<ll, ll> next;
        switch(s[p]) {
            case 'L':
                next = {x-1, y};
                break;
            case 'R':
                next = {x+1, y};
                break;
            case 'U':
                next = {x, y+1};
                break;
            default:
                next = {x, y-1};
        }
        if (P.find(next) != P.end()) dfs(p+1, x, y);
        else {
            if (!vis[next.first][next.second]) {
                P.emplace(next);
                dfs(p+1, x, y);
                P.erase(next);
            }
            dfs(p+1, next.first, next.second);
        }
        if (!flag) vis[x][y] = 0;
    };
    dfs(0, 25, 25);
    cout<<F.size()<<"\n";
    for (auto &[a, b]: F) cout<<a-25<<" "<<b-25<<"\n";
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
