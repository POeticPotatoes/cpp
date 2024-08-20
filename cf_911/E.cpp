<<<<<<< Updated upstream
#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;
#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
=======
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
>>>>>>> Stashed changes
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

    vv<ll> adj(n+1);
    vll A(n+1);
    FORN(i, 1, n) cin>>A[i];
    REP(i, m) {
        ll a, b;
        cin>>a>>b;
        if (a != b) adj[a].eb(b);
    }

    FORN(i, 1, n) {
        sort(all(adj[i]));
        auto p = unique(all(adj[i]));
        adj[i].resize(p-adj[i].begin());
    }

    vll lo(n+1), ord(n+1), vis(n+1), comp(n+1);
<<<<<<< Updated upstream

    vector<pair<ll, ll>> alt;
    vv<ll> dir;
    ll dep=0;
=======
    stack<ll> stk;

    vector<pair<ll, ll>> alt;
    vv<ll> dir;
    ll dep=0, cnt=0;
>>>>>>> Stashed changes

    function<void(ll)> tarjan = [&] (ll v) {
        vis[v] = 1;
        lo[v] = ord[v] = ++dep;
<<<<<<< Updated upstream

        for (auto c: adj[v]) {
            // deb(v, c, vis[c]);
=======
        stk.push(v);

        for (auto c: adj[v]) {
>>>>>>> Stashed changes
            if (!vis[c]) {
                tarjan(c);
                lo[v] = min(lo[v], lo[c]);
            } else if (vis[c]==1) lo[v] = min(lo[v], ord[c]);
        }
<<<<<<< Updated upstream
        vis[v]=2;
    };

    function<void(ll, ll)> build = [&] (ll v, ll p) {
        if (vis[v]==3) return;
        vis[v] = 3;
        ll id = p;
        if (lo[v] == ord[v]) { // SCC
            id = alt.size();
            alt.eb(0, 0);
            dir.eb(vll());
        }
        comp[v] = id;
        alt[id].first++, alt[id].second += A[v];

        for (auto c: adj[v]) {
            build(c, id);
=======
        
        if (lo[v] == ord[v]) {
            ll c = -1;
            while (c != v) {
                c = stk.top(); stk.pop();
                vis[c] = 2;
                comp[c] = cnt;
            }
            cnt++;
        }
    };

    function<void(ll)> build = [&] (ll v) {
        if (vis[v]==3) return;
        vis[v] = 3;
        ll id = comp[v];
        alt[id].first++, alt[id].second += A[v];

        for (auto c: adj[v]) {
            build(c);
>>>>>>> Stashed changes
            if (comp[c] != id) dir[id].eb(comp[c]);
        }
    };

    FORN(i, 1, n) if (!vis[i]) tarjan(i);
    // deb(lo, ord, vis);
<<<<<<< Updated upstream
    FORN(i, 1, n) if (vis[i] != 3) build(i, 0);
    deb(comp, alt);
    // deb(dir);
=======
    alt = vector<pair<ll, ll>>(cnt);
    dir = vv<ll>(cnt);
    FORN(i, 1, n) if (vis[i] != 3) build(i);
    deb(comp, alt);
    deb(dir);

    ll sum=0, tot=0, chk=0;
    REP(i, alt.size()) sum+=alt[i].first, tot+=alt[i].second;
    FORN(i, 1, n) chk += A[i];
    assert(sum==n && tot==chk);
>>>>>>> Stashed changes

    vector<pair<ll, ll>> DP(alt.size());

    pair<ll, ll> ans;

    auto compare = [&] (pair<ll, ll> a, pair<ll, ll> b) {
        if (a.first > b.first) return a;
        if (a.first == b.first && a.second < b.second) return a;
        return b;
    };

    function<void(ll)> count = [&] (ll v) {
        DP[v] = alt[v];
        for (auto c: dir[v]) {
            if (!DP[c].first) count(c);
            DP[v] = compare(DP[v], make_pair(DP[c].first+alt[v].first, 
                        DP[c].second+alt[v].second));
        }
        deb(v, alt[v], DP[v]);
        ans = compare(ans, DP[v]);
    };

    REP(i, alt.size()) if (!DP[i].first) count(i);
    cout<<ans.first<<" "<<ans.second<<"\n";
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
