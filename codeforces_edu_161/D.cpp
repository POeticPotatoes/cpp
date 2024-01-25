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
    segtree(ll s): sz(s), st(sz*4) {
        build(0, sz-1, 1);
    }

    private:
        void build(ll l, ll r, ll k) {
            st[k] = r;
            if (l==r) return;
            ll m = (l+r) >>1;
            build(l, m, k<<1);
            build(m+1, r, k<<1|1);
        }

        void del(ll l, ll r, ll k, ll p) {
            if (l==r) {
                st[k] = -1;
                return;
            }
            ll m = (l+r) >>1;
            if (p<=m) del(l, m, k<<1, p);
            else del(m+1, r, k<<1|1, p);
            st[k] = max(st[k<<1], st[k<<1|1]);
        }

        ll query(ll l, ll r, ll k, ll p) {
            if (r==p) return st[k];
            ll m = (l+r)>>1;
            if (p<=m) return query(l, m, k<<1, p);
            else return max(st[k<<1], query(m+1, r, k<<1|1, p));
        }

    public:
        void del(ll p) {
            del(0, sz-1, 1, p);
        }

        ll query(ll p) {
            if (p<0 || p>=sz) return -1;
            return query(0, sz-1, 1, p);
        }
};

void solve() {
    ll n;
    cin>>n;
    vll A(n), D(n);
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>D[i];

    segtree hi(n), lo(n);

    set<ll> cool;
    REP(i, n) cool.insert(i);

    ll cnt=0;
    while (cool.size()) {
        // deb(cool);
        set<ll> next, del;

        for (ll v: cool) {
            ll l = hi.query(v-1),
               r = n-1-lo.query(n-2-v);
            // deb(v, l, r);
            ll t=0;
            t += l>=0?A[l]:0;
            t += r<n?A[r]:0;
            if (t > D[v])
                del.insert(v);
        }

        for (ll v: del) {
            hi.del(v);
            lo.del(n-1-v);
        }

        // deb(del);

        cout<<del.size()<<" ";

        for (ll v:del) {
            ll l = hi.query(v-1),
               r = n-1-lo.query(n-2-v);
            if (l>=0) next.insert(l);
            if (r<n) next.insert(r);
        }

        cool = next;
        cnt++;
    }
    FOR(i, cnt, n) cout<<"0 ";
    cout<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
