#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
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

constexpr ll MOD = 998244353;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 1e5+1;

ll n, ans, A[N], B[N], vis[N], cyc[N];
vector<multiset<ll>> edges;

void clean(ll k) {
    vector<int> e;
    for (int i: edges[k])
        if (vis[i]) e.eb(i);
    for (auto i: e) edges[k].erase(i);
    if (edges[k].size()>1) return;
    vis[k] = 2;
    auto i = *edges[k].begin();
    if (edges[i].size()==1)
        clean(i);
}

bool check(ll k, ll orig) {
    if (vis[k]) return false;
    cyc[k]=1;
    for (auto i: edges[k]) {
        if (i==orig) return true;
        if (!cyc[i])
            return check(i, orig);
    }
    return false;
}

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>B[i];
    // cout<<"DOING "<<endl<<n<<endl;
    // REP(i, n) cout<<A[i]<<" ";
    // cout<<endl;
    // REP(i, n) cout<<B[i]<<" ";
    // cout<<endl;
    ans = 1;
    edges = vector<multiset<ll>>(n+1);
    memset(vis+1, 0, sizeof(ll)*n);
    memset(cyc+1, 0, sizeof(ll)*n);
    REP(i, n) {
        if (A[i] == B[i]) {
            if (vis[A[i]]++) return (void) (cout<<0<<endl);
            continue;
        }
        edges[A[i]].insert(B[i]);
        edges[B[i]].insert(A[i]);
    }
    FOR(i, 1, n+1) {
        if (vis[i]) continue;
        if (edges[i].size() == 0)
            return (void) (cout<<0<<endl);
        clean(i);
    }

    ans = 1;
    FOR(i, 1, n+1) {
        if (vis[i]) {
            ans = ans*(vis[i]==1?n:1)%MOD;
            continue;
        }
        if (edges[i].size() != 2)
            return (void) (cout<<0<<endl);
        if (cyc[i]) continue;
        cyc[i] = 1;
        if (!check(*edges[i].begin(), i))
            return (void) (cout<<0<<endl);
        ans = ans*2%MOD;
    }
    cout<<ans<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
