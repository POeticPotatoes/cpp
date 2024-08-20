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
    ll n;
    cin>>n;
    ll lo=-1, hi=-1, x=0;

    auto query = [&] (ll p) {
        cout<<"? "<<p<<endl;
        char s;
        cin>>s;
        if (s != '=') x += s=='<'?-1:1;
        return s;
    };

    FORN(i, 1, n) {
        ll res = query(i);
        if (res == '>') {
            if (lo > -1) query(lo);
            continue;
        }
        while (res == '<') res = query(i);
        lo = i;
    }
    FORN(i, 1, n) {
        ll res = query(i);
        if (res == '<') {
            if (hi > -1) query(hi);
            continue;
        }
        while (res == '>') res = query(i);
        hi = i;
    }

    // hi and lo acquired, x is currently n
    x = n;

    auto shift = [&] (ll v) {
        while (x!=v) query(x<v?hi:lo);
    };

    vll ans(n+1);

    function<void(ll, ll, vll)> qs = [&] (ll l, ll r, vll A) {
        deb(l, r, A);
        if (l==r) {
            deb("!", l, A[0]);
            assert(A.size()==1);
            ans[A[0]] = l;
            return;
        }
        ll m = (l+r)/2;
        vll sm, lr;
        for (auto p: A) {
            shift(m);
            auto res = query(p);
            if (res == '>') lr.eb(p);
            else sm.eb(p);
        }
        qs(l, m, sm);
        qs(m+1, r, lr);
    };

    vll orig(n);
    iota(all(orig), 1);

    qs(1, n, orig);
    cout<<"! ";
    FORN(i, 1, n) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
