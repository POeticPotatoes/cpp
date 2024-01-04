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
    vll A(n), C(n);
    vector<pair<ll, ll>> st(4*n), O(m);
    REP(i, n) cin>>A[i];
    REP(i, m) {
        cin>>O[i].first>>O[i].second;
        O[i].first--, O[i].second--;
    }

    function<void(ll, ll, ll)> build = [&](ll l, ll r, ll k) {
        if (l == r) {
            st[k] = {C[l], C[l]};
            return;
        }
        ll mid = (l+r)>>1;
        build(l, mid, k<<1); build(mid+1, r, (k<<1)+1);
        st[k] = {st[k<<1].first + st[(k<<1)+1].first, -1};
    };

    function<void(ll, ll, ll)> propagate = [&](ll l, ll r, ll k) {
        ll mid = (l+r)>>1;
        st[k<<1] = {st[k].second * (mid-l+1), st[k].second};
        st[(k<<1)+1] = {st[k].second * (r-mid), st[k].second};
        st[k].second = -1;
    };

    function<void(ll, ll, ll, ll, ll, ll)> update = [&](ll l, ll r, ll k, ll v, ll L, ll R) {
        deb(l, r, k, v, L, R);
        if ((L<=l && R>=r) || st[k].second==v) {
            st[k] = {(r-l+1)*v, v};
            return;
        }
        if (st[k].second != -1) propagate(l, r, k);
        ll mid = (l+r)>>1;
        if (L<=mid) update(l, mid, k<<1, v, L, R);
        if (R>mid)  update(mid+1, r, (k<<1)+1, v, L, R);
        st[k].first = st[k<<1].first + st[(k<<1)+1].first;
    };

    function<ll(ll, ll, ll, ll, ll)> sum = [&] (ll l, ll r, ll k, ll L, ll R) {
        if (L<=l && R>=r) return st[k].first;
        if (st[k].second != -1) propagate(l, r, k);
        ll mid = (l+r)>>1, s = 0;
        if (L<=mid) s += sum(l, mid, k<<1, L, R);
        if (R>mid)  s += sum(mid+1, r, (k<<1)+1, L, R);
        return s;
    };

    function<ll(ll, ll, ll, ll)> read = [&] (ll l, ll r, ll k, ll p) {
        if (l==r || st[k].second != -1) return st[k].second;
        if (st[k].second != -1) propagate(l, r, k);
        ll mid = (l+r)>>1;
        if (p<=mid) return read(l, mid, k<<1, p);
        else return read(mid+1, r, (k<<1)+1, p);
    };

    ll l = 1, r = n;
    while (l<r) {
        ll mid = (l+r)>>1;
        REP(i, n) C[i] = A[i]>mid;
        deb(mid, C);
        build(0, n-1, 1);
        // REP(i, n) cout<<read(0, n-1, 1, i);
        // cout<<"\n";
        REP(i, m) {
            deb(O[i]);
            if (O[i].first < O[i].second) {
                ll s = sum(0, n-1, 1, O[i].first, O[i].second);
                if (s<O[i].second-O[i].first+1) {
                    deb("update(0, n-1, 1, 0", O[i].first, O[i].second-s);
                    update(0, n-1, 1, 0, O[i].first, O[i].second-s);
                }
                if (s) {
                    deb("update(0, n-1, 1, 1", O[i].second-s+1, O[i].second);
                    update(0, n-1, 1, 1, O[i].second-s+1, O[i].second);
                }
            } else {
                ll s = sum(0, n-1, 1, O[i].second, O[i].first);
                if (s) {
                    deb("update(0, n-1, 1, 1", O[i].second, O[i].second+s-1);
                    update(0, n-1, 1, 1, O[i].second, O[i].second+s-1);
                }
                if (s<O[i].first-O[i].second+1) {
                    deb("update(0, n-1, 1, 0", O[i].second+s, O[i].first);
                    update(0, n-1, 1, 0, O[i].second+s, O[i].first);
                }
            }
            // REP(j, n) cout<<read(0, n-1, 1, j);
            // cout<<"\n";
        }
        ll v = read(0, n-1, 1, n>>1);
        // REP(i, n) cout<<read(0, n-1, 1, i);
        // cout<<"\n";
        if (v) l = mid+1;
        else r = mid;
    }
    cout<<l<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
