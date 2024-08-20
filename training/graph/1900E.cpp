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
    vll A(n+1);
    vv<ll> adj(n+1);
    FORN(i, 1, n) cin>>A[i];
    REP(i, m) {
        ll a, b;
        cin>>a>>b;
        if (a!=b) adj[a].eb(b);
    }
    FORN(i, 1, n) {
        sort(all(adj[i]));
        auto p = unique(all(adj[i]));
        adj[i].resize(p-adj[i].begin());
    }

    vll ord(n+1), lo(n+1), comp(n+1), vis(n+1);
    ll cnt=0, scc=0;
    stack<ll> add;

    function<void(ll)> tarjan = [&] (ll v) {
        vis[v] = 1;
        lo[v] = ord[v] = ++cnt;
        add.push(v);

        for (auto c: adj[v]) {
            if (!vis[c]) {
                tarjan(c);
                lo[v] = min(lo[v], lo[c]);
            } else if (vis[c]==1)
                lo[v] = min(lo[v], ord[c]);
        }

        if (lo[v] == ord[v]) {
            ll c = -1;
            while (c != v) {
                c = add.top(); add.pop();
                comp[c] = scc;
                vis[c] = 2;
            }
            scc++;
        }
    };

    FORN(i, 1, n) if (!vis[i]) tarjan(i);

    vector<pair<ll, ll>> SCC(scc);
    vv<ll> sccadj(scc);
    FORN(i, 1, n) {
        SCC[comp[i]].first++;
        SCC[comp[i]].second += A[i];
        for (auto c: adj[i]) if (comp[c] != comp[i])
            sccadj[comp[i]].eb(comp[c]);
    }

    auto compare = [&] (pair<ll, ll> a, pair<ll, ll> b) {
        if (a.first<b.first) return b;
        if (a.first==b.first && b.second<a.second) return b;
        return a;
    };

    pair<ll, ll> ans;
    vector<pair<ll, ll>> DP(scc);
    function<void(ll)> count = [&] (ll v) {
        if (vis[v]==3) return;
        vis[v] = 3;

        DP[v] = SCC[v];
        
        for (auto c: sccadj[v]) {
            count(c);
            DP[v] = compare(DP[v], make_pair(DP[c].first+SCC[v].first, 
                        DP[c].second+SCC[v].second));
        }
        ans = compare(ans, DP[v]);
    };

    REP(i, scc) if (vis[i]!=3) count(i);
    cout<<ans.first<<" "<<ans.second<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
