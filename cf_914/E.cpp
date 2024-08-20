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

struct node {
    ll val;
    ll lazy;
};

struct segtree {
    ll sz;
    vector<node> st;

    segtree(vll &V): sz(V.size()), st(sz*4) {
        build(0, sz-1, 1, V);
    }

    void build(ll l, ll r, ll k, vll &V) {
        if (l==r) {
            st[k].val = V[l];
            return;
        }
        ll m = (l+r)>>1;
        build(l, m, k<<1, V);
        build(m+1, r, k<<1|1, V);
        st[k].val = max(st[k<<1].val, st[k<<1|1].val);
    }

    void propagate(ll k) {
        if (!st[k].lazy) return;
        st[k<<1].lazy += st[k].lazy;
        st[k<<1].val += st[k].lazy;
        st[k<<1|1].lazy += st[k].lazy;
        st[k<<1|1].val += st[k].lazy;
        st[k].lazy = 0;
    }

    void update(ll l, ll r, ll k, ll x, ll y, ll v) {
        if (x<=l && y>=r) {
            st[k].lazy += v;
            st[k].val += v;
            return;
        }
        propagate(k);
        ll m = (l+r)>>1;
        if (x<=m) update(l, m, k<<1, x, y, v);
        if (y>m) update(m+1, r, k<<1|1, x, y, v);
        st[k].val = max(st[k<<1].val, st[k<<1|1].val);
    }

    void update(ll x, ll y, ll v) {
        if (y<x) return;
        update(0, sz-1, 1, x, y, v); 
    }

    ll query(ll l, ll r, ll k, ll x, ll y) {
        if (x<=l && y>=r) return st[k].val;
        propagate(k);
        ll m = (l+r)>>1;
        ll ans = -1;
        if (x<=m) ans = max(ans, query(l, m, k<<1, x, y));
        if (y>m) ans = max(ans, query(m+1, r, k<<1|1, x, y));
        return ans;
    }

    ll query(ll x, ll y) {
        ll res = query(0, sz-1, 1, x, y);
        deb("query", x, y, res);
        return res;
    }
};

void solve() {
    ll n, q;
    cin>>n>>q;
    vv<ll> adj(n+1);

    REP(i, n-1) {
        ll a, b;
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    vll order, in(n+1), out(n+1);
    function<void(ll, ll, ll)> dfs = [&](ll v, ll p, ll d) {
        in[v] = order.size();
        order.eb(d);

        for (auto c: adj[v]) if (c != p) {
            dfs(c, v, d+1);
        }

        out[v] = order.size();
        order.eb(d);
    };

    dfs(1, 0, 1);
    ll o = order.size();
    deb(order);
    deb(in);
    deb(out);
    segtree ST(order);

    vv<pair<ll, vll>> Q(n+1);
    vll ans(q), nxt(n+1);
    REP(i, q) {
        ll x, s;
        cin>>x>>s;
        vll C(s);
        REP(j, s) cin>>C[j];
        Q[x].eb(i, C);
    }

    auto check = [&]() {
        vll C;
        REP(i, o) C.eb(ST.query(i, i));
        return C;
    };

    function<void(ll, ll)> answer = [&](ll v, ll p) {
        ST.update(0, in[v]-1, 1);
        ST.update(in[v], out[v], -1);
        ST.update(out[v]+1, o-1, 1);
        deb(v);

        for (auto query: Q[v]) {
            deb(v, query.first, query.second);
            set<pair<ll, ll>> exclude;
            for (auto x: query.second) {
                if (in[x]<=in[v] && out[x]>=in[v]) {
                    exclude.insert({0, in[nxt[x]]-1});
                    exclude.insert({out[nxt[x]]+1, o-1});
                } else
                    exclude.insert({in[x], out[x]});
            }
            deb(exclude);

            ll l = 0, res=0;
            for (auto &[a, b]: exclude) {
                if (a<=l) {
                    l = max(l, b+1);
                    continue;
                }
                res = max(res, ST.query(l, a-1));
                l = b+1;
            }
            res = max(res, ST.query(l, o-1));
            ans[query.first] = res;
        }

        for (auto c: adj[v]) if (c!=p) {
            nxt[v] = c;
            answer(c, v);
        }
        ST.update(0, in[v]-1, -1);
        ST.update(in[v], out[v], 1);
        ST.update(out[v]+1, o, -1);
    };

    answer(1, 0);
    REP(i, q) cout<<ans[i]<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
