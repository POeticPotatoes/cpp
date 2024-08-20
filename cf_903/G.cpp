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
    ll n;
    vll st;
    segtree(ll sz): n(sz), st(n*4) {}

    private:
        void propagate(ll k) {
            st[k<<1] += st[k];
            st[k<<1|1] += st[k];
            st[k] = 0;
        }

        void update(ll l, ll r, ll k, ll x, ll y, ll v) {
            if (l>=x && r<=y) {
                st[k] += v;
                return;
            }
            propagate(k);
            ll mid = (l+r)/2;
            if (x<=mid) update(l, mid, k<<1, x, y, v);
            if (y>mid) update(mid+1, r, k<<1|1, x, y, v);
        }

        ll query(ll l, ll r, ll k, ll p) {
            if (l==r) return st[k];
            propagate(k);
            ll mid = (l+r)/2;
            if (p<=mid) return query(l, mid, k<<1, p);
            else return query(mid+1, r, k<<1|1, p);
        }
    
    public:
        void update(ll l, ll r, ll v) {
            update(0, n-1, 1, l, r, v);
        }

        ll query(ll p) {
            ll res = query(0, n-1, 1, p);
            //deb("query", p, res);
            return res;
        }
};

void solve() {
    ll n, m;
    cin>>n>>m;
    string s;
    cin>>s;

    set<ll> twos, threes;
    segtree ST(n);

    REP(i, n-1) if (s[i] == s[i+1]) twos.insert(i);
    FOR(i, 1, n-1) if (s[i-1] == s[i+1]) threes.insert(i-1);

    auto check = [&] (ll o, ll d) {
        vll seg;

        REP(i, d) seg.eb((s[o+i] - 'a' + ST.query(o+i))%26);

        //deb(o, d);
        // REP(i, d) {
        //     cout<<(char) ('a' + seg[i]);
        // }
        // cout<<"\n";

        auto p = twos.upper_bound(o-1);
        while (p!=twos.end() && *p - o < d-1) {
            twos.erase(p);
            p = twos.upper_bound(o);
        }
        REP(i, d-1) if (seg[i] == seg[i+1]) twos.insert(o+i);

        p = threes.upper_bound(o-1);
        while (p!=threes.end() && *p - o < d-2) {
            threes.erase(p);
            p = threes.upper_bound(o);
        }
        REP(i, d-2) if (seg[i] == seg[i+2]) threes.insert(o+i);
        //deb(twos, threes);
    };

    REP(i, m) {
        //deb(i, twos, threes);
        ll t, l, r;
        cin>>t>>l>>r;
        l--, r--;
        if (t==1) {
            ll v;
            cin>>v;
            ST.update(l, r, v);
            ll x = max(0LL, l-5), y = min(n, l+5);
            check(x, y-x);
            x = max(0LL, r-5), y=min(n, r+5);
            check(x, y-x);
        } else {
            auto p1 = twos.upper_bound(l-1);
            auto p2 = twos.upper_bound(r-1);
            if (p1 != p2) {
                cout<<"NO\n";
                continue;
            }
            if (r-l < 2) {
                cout<<"YES\n";
                continue;
            }
            p1 = threes.upper_bound(l-1);
            p2 = threes.upper_bound(r-2);
            if (p1 != p2) {
                cout<<"NO\n";
            } else cout<<"YES\n";
        }
    }
}

int main() {
    IO;
    int t=1;
    cin >> t;
    while (t--) solve();
}
