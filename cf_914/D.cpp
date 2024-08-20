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

struct segtree {
    ll sz;
    vll st;

    segtree(vll &A): sz(A.size()), st(sz*4) {
        build(0, sz-1, 1, A);
    }

    void build(ll l, ll r, ll k, vll &A) {
        if (l==r) {
            st[k] = A[l];
            return;
        }
        ll m = (l+r)>>1;
        build(l, m, k<<1, A);
        build(m+1, r, k<<1|1, A);
        st[k] = max(st[k<<1], st[k<<1|1]);
    }

    ll query(ll l, ll r, ll k, ll x, ll y) {
        if (x<=l && y>=r) return st[k];
        ll m = (l+r)>>1;
        ll res = -INF;
        if (x<=m) res = max(res, query(l, m, k<<1, x, y));
        if (y>m) res = max(res, query(m+1, r, k<<1|1, x, y));
        return res;
    }

    ll query(ll x, ll y) {
        return query(0, sz-1, 1, x, y);
    }
};

void solve() {
    ll n;
    cin>>n;
    vll A(n), B(n);
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>B[i];
    vll INV(n);
    REP(i, n) INV[i] = -B[i];

    segtree ST(A), CH(INV);
    map<ll, vll> O;

    REP(i, n) O[A[i]].eb(i);

    REP(i, n) {
        bool flag=false;
        auto p = upper_bound(all(O[B[i]]), i);
        if (p != O[B[i]].begin()) {
            ll l = *prev(p);
            ll hi = ST.query(l, i);
            ll lo = -CH.query(l, i);
            if (hi<=B[i] && lo>=B[i]) flag = true;
        }
        if (p != O[B[i]].end()) {
            ll r = *p;
            ll hi = ST.query(i, r);
            ll lo = -CH.query(i, r);
            if (hi<=B[i] && lo>=B[i]) flag = true;
        }
        if (!flag) return (void) (cout<<"NO\n");
    }
    cout<<"YES\n";
}

int main() {
    IO;
    int t=1;
    cin >> t;
    while (t--) solve();
}
