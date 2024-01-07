#include <bits/stdc++.h>
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

struct segment {
    int left=-1;
    int right=-1;
    bool flag=false;
    set<ll> val;
};

void solve() {
    ll n, q;
    cin>>n>>q;

    vector<segment> segtree(1);
    segtree.reserve(q*30);

    function<void(ll)> propagate = [&](ll k) {
        for (auto c: segtree[k].val) {
            if (c<0) {
                segtree[segtree[k].left].val.erase(-c);
                segtree[segtree[k].left].val.insert(c);
                segtree[segtree[k].right].val.erase(-c);
                segtree[segtree[k].right].val.insert(c);
            }
            else {
                segtree[segtree[k].left].val.erase(-c);
                segtree[segtree[k].left].val.insert(c);
                segtree[segtree[k].right].val.erase(-c);
                segtree[segtree[k].right].val.insert(c);
            }
        }
        segtree[k].val.clear();
    };
    
    function<void(ll, ll, ll, ll, ll, ll)> update = [&](ll l, ll r, ll k, ll X, ll Y, ll v) {
        // deb(l, r, k, X, Y, v);
        auto &cur = segtree[k];
        // deb(cur.val);
        ll m = (l+r)>>1;
        if (X<=l && Y>=r) {
            cur.val.erase(-v);
            cur.val.insert(v);
            // deb(cur.val);
            return;
        }
        if (!cur.flag) {
            cur.left = segtree.size();
            segtree.push_back(segment());
            cur.right = segtree.size();
            segtree.push_back(segment());
            cur.flag=true;
        }
        if (cur.val.size()) propagate(k);
        if (X<=m) update(l, m, cur.left, X, Y, v);
        if (Y>m) update(m+1, r, cur.right, X, Y, v);
    };

    function<ll(ll, ll, ll, ll)> query = [&](ll l, ll r, ll k, ll q) {
        // deb(l, r, k, q);
        auto &cur = segtree[k];
        // deb(cur.val);
        ll m = (l+r)>>1;
        if (l<=q && q<=r && !cur.flag) {
            ll count=0;
            for (auto c: cur.val) count+=c>0;
            // deb(cur.val);
            return count;
        }
        if (cur.val.size()) propagate(k);
        if (q<=m) return query(l, m, cur.left, q);
        else return query(m+1, r, cur.right, q);
    };

    REP(i, q) {
        char c;
        cin>>c;
        if (c=='?') {
            ll x;
            cin>>x;
            cout<<query(1, n, 0, x)<<endl;
        } else {
            ll l, r, x;
            cin>>l>>r>>x;
            if (c=='-') x*=-1;
            update(1, n, 0, l, r, x);
        }
        // deb("-----------------");
    }
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
