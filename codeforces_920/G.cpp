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

struct fenwick {
    ll sz;
    vll ft;
    fenwick(ll s): sz(s), ft(sz+1) {}

    void add(ll p, ll v) {
        p++;
        for (int i=p;i<=sz;i += (i&-i)) {
            ft[i]+=v;
        }
    }

    ll query(ll p) {
        p++;
        if (p==0) return 0;
        ll res=0;
        for (int i=p;i;i-=(i&-i)) {
            res += ft[i];
        }
        return res;
    }

    ll query(ll l, ll r) {
        ll a = query(l-1),
           b = query(r);
        deb(l, r, b-a);
        return b-a;
    }

    void p() {
        deb(ft);
    }
};

void solve() {
    ll n, m, k;
    cin>>n>>m>>k;
    k++;
    vector<string> A(n);
    REP(i, n) cin>>A[i];
    vector<fenwick> row(n, fenwick(m)), col(m, fenwick(n));

    REP(i, n) REP(j, m) {
        if (A[i][j] == '#') {
            row[i].add(j, 1);
            col[j].add(i, 1);
        }
    }

    ll ans=0;

    auto check = [&] (ll n, ll m, vector<string> &A, vector<fenwick> &row, vector<fenwick> &col) {
        ROF(i, m-1, -k-1) {
            // deb(i, max(0LL, i), min(m-1, i+k-1));
            ll cur = row[0].query(max(0LL, i), min(m-1, i+k-1));
            ans = max(ans, cur);
            ll t = min(m-i, n);
            // deb(i, t);
            FOR(x, 1, t) {
                ll y = i+x;
                // deb(x, y);
                if (y>0) {
                    // deb(y-1, max(0LL, x-k), x-1);
                    cur -= col[y-1].query(max(0LL, x-k), x-1);
                }
                // deb(x, max(0LL, y), min(m-1, y+k-1));
                cur += row[x].query(max(0LL, y), min(m-1, y+k-1));
                // deb(x, y, cur);
                ans = max(ans, cur);
            }
            // deb(ans);
        }

        FOR(i, 0, m+k) {
            ll cur = row[n-1].query(max(0LL, i-k+1), min(m-1, i));
            deb(
            ans = max(ans, cur);
            ll t = min(i+1, n);
            FOR(j, 1, t) {
                ll x=n-1-j, y = i-j;
                if (y<m-1) {
                    cur -= col[y+1].query(min(n-1, x+1), min(n-1, x+k));
                }
                cur += row[x].query(max(0LL, y-k+1), min(m-1, y));
                deb(x, y, cur);
                ans = max(ans, cur);
            }
        }
    };

    check(n, m, A, row, col);
    check(m, n, A, col, row);

    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
