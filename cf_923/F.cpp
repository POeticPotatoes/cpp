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
    ll n, m;
    cin>>n>>m;
    vv<pair<ll, ll>> adj(n+1);

    REP(i, m) {
        ll u, v, w;
        cin>>u>>v>>w;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }

    ll cnt=0, a, b, sm=INF;
    vll vis(n+1), ord(n+1);
    function<void(ll, ll)> tarjan = [&] (ll u, ll p) {
        if (vis[u]) return;
        vis[u] = 1;
        ord[u] = ++cnt;
        ll res = ord[u];
        for (auto &[c, w]: adj[u]) if (c!=p) {
            tarjan(c, u);
            if (ord[c] <= ord[u] && w<sm) {
                a=u, b=c, sm=w;
            }
            res = min(res, ord[c]);
        }
        ord[u] = res;
    };

    FORN(i, 1, n) if (!vis[i]) tarjan(i, -1);
    deb(a, b, sm, ord);

    vis = vll(n+1);
    vis[a] = a;
    queue<ll> Q;
    for (auto &[c, w]: adj[a]) if (c!=b) {
        Q.push(c);
        vis[c] = a;
    }

    while (Q.size()) {
        ll v = Q.front(); Q.pop();
        if (v==b) break;
        for (auto &[c, w]: adj[v]) if (!vis[c]) {
            vis[c] = v;
            Q.push(c);
        }
    }

    deb(vis);

    vll ans(1, a);
    ll cur = b;
    while (cur!=a) {
        ans.eb(cur);
        cur = vis[cur];
    }
    ll k = ans.size();
    cout<<sm<<" "<<k<<"\n";
    REP(i, k) cout<<ans[i]<<" ";
    cout<<"\n";
    cout.flush();
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
