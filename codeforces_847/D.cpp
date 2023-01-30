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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
const ll N = 3e5;

ll n, c, vis[N], P[N], A[N], D[N], a, b;
vv<ll> adj;

ll bfs(ll k, ll f) {
    deb(k, vis[k], f, vis[k], D[k]);
    if (vis[k] == f-1) return D[k];
    //deb(k, f);
    queue<pair<ll, ll>> q;
    q.push({k, 0});
    vis[k] = f;
    D[k] = 0;
    while (q.size()) {
        ll d = q.front().second, j = q.front().first;
        deb(q.front(), d, P[j]);
        for (auto i: adj[j]) {
            if (vis[i] == f) continue;
            vis[i] = f;
            D[i] = min(D[i], d+1);
            if (P[i]) {
                deb(i, d, D[i]);
                return d+1;
            }
            q.push({i, d+1});
        }
        q.pop();
    }
    return 0;
}

void solve() {
    cin>>n>>c;
    FORN(i, 1, n-1) cin>>A[i];
    adj = vv<ll>(n);
    memset(P, 0, sizeof(ll)*n);
    memset(vis, 0, sizeof(ll)*n);
    memset(D, 0x3f, sizeof(ll)*n);

    REP(i, n-1) {
        cin>>a>>b;
        adj[--a].eb(--b);
        adj[b].eb(a);
    }
    
    ll cur, m=inf;
    vll ans;
    bfs(--c, 2);
    P[c] = 1;
    FORN(i, 1, n-1) {
        if (m==1) {
            ans.eb(1);
            continue;
        }
        cur = bfs(--A[i], i+2);
        m = max(1ll, min(m, cur));
        ans.eb(m);
        P[A[i]] = 1;
    }
    REP(i, n-1) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
