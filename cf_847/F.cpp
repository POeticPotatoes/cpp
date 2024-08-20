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
constexpr ll N = 3e5;

ll n, A[N], a, b, D[N], P[N];
vv<ll> adj;

void dfs(ll k) {
    for (auto i: adj[k]) {
        if (i == P[k]) continue;
        P[i] = k;
        dfs(i);
    }
}

void solve() {
    cin>>n;
    adj = vv<ll>(n);
    REP(i, n) cin>>A[i];
    REP(i, n-1) {
        cin>>a>>b;
        adj[--a].eb(--b);
        adj[b].eb(a);
    }
    memset(P, 0x3f, sizeof(ll)*n);
    memset(D, 0x3f, sizeof(ll)*n);
    // As a tree, all nodes can be valid roots
    P[0] = -1;
    dfs(0);

    ll ans=inf;
    vll v;
    REP(i, n) {
        ll d=0, cur=--A[i];
        while (cur>-1 && d<ans) {
            deb(cur, ans, d, D[cur], d+D[cur]);
            ans = min(ans, d+D[cur]);
            D[cur] = min(D[cur], d);
            cur = P[cur];
            d++;
        }
        deb(ans);
        v.eb(ans);
    }
    FOR(i, 1, n) cout<<v[i]<<" ";
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
