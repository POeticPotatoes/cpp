#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;
#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
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
    vll st, lazy;
    ll n;

    segtree(ll n): st(vll(n*4)), lazy(vll(n*4)), n(n) {}

    void propagate(ll p) {
        st[p<<1] += lazy[p];
        lazy[p<<1] += lazy[p];

        st[p<<1|1] += lazy[p];
        lazy[p<<1|1] += lazy[p];

        lazy[p] = 0;
    }

    void update(ll p, ll l, ll r, ll x, ll y, ll v) {
        if (l>=x && r<=y) {
            st[p] += v;
            lazy[p] += v;
            return;
        }

        propagate(p);
        ll m = (l+r)>>1;

        if (x<=m) update(p<<1, l, m, x, y, v); 
        if (y>m) update(p<<1|1, m+1, r, x, y, v);

        st[p] = min(st[p<<1], st[p<<1|1]);
    }

    ll query(ll p, ll l, ll r, ll x, ll y) {
        if (l>=x && r<=y) return st[p];

        propagate(p);
        ll m = (l+r)>>1;

        ll res = INF;
        if (x<=m) res = min(res, query(p<<1, l, m, x, y));
        if (y>m) res = min(res, query(p<<1|1, m+1, r, x, y));

        return res;
    }

    void update(ll x, ll y, ll v) {
        deb("Upd", x, y, v);
        update(1, 0, n-1, x, y, v);
    }

    ll query(ll x, ll y) {
        ll v = query(1, 0, n-1, x, y);
        deb("Quer", x, y, v);
        return v;
    }
};

void solve() {
    ll n;
    cin>>n;

    vll A(n+1);
    FORN(i, 1, n) cin>>A[i];

    map<ll, ll> fir, sec;
    segtree st(n+1);

    ll ans=0;

    FORN(i, 1, n) {
        deb(i, A[i]);
        ll la=0;
        if (fir[A[i]]) {
            if (sec[A[i]]) {
                st.update(1, sec[A[i]], 1);
                la = sec[A[i]];
            }
            st.update(1, fir[A[i]], -2);
            sec[A[i]] = fir[A[i]];
        }
        st.update(1, i, 1);
        fir[A[i]] = i;

        deb(fir[A[i]], sec[A[i]]);

        if (st.query(1, i) == 0) {
            ans++;

            // undo
            st.update(1, sec[A[i]], 2);
            fir[A[i]] = sec[A[i]];
            sec.erase(sec.find(A[i]));

            if (la) {
                st.update(1, la, -1);
                sec[A[i]] = la;
            }
        }
    }

    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
