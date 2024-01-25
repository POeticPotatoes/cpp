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
    ll n, q;
    cin>>n>>q;
    vector<pair<ll, ll>> A(n+1);
    vll Q(q);
    FORN(i, 1, n) cin>>A[i].first>>A[i].second;
    REP(i, q) cin>>Q[i];
    vv<ll> seg;
    vll sz, tldr;

    vll cur;
    ll size=0;
    FORN(i, 1, n) {
        if (A[i].first == 1) {
            cur.eb(A[i].second);
            size++;
        } else {
            tldr.eb(seg.size());
            seg.push_back(cur);
            sz.push_back(size);
            cur.clear();
            A[i].second = min(A[i].second, (INF/size));
            tldr.eb(-size);
            size *= A[i].second+1;
            sz.push_back(size);
            if (size > INF) break;
        }
        deb(i, A[i], size);
    }
    if (cur.size()) {
        tldr.eb(seg.size());
        seg.push_back(cur);
        sz.push_back(size);
    }
    
    deb(seg);
    deb(sz);
    deb(tldr);

    ll c = sz.back();

    REP(i, q) {
        assert(Q[i] <= c);
        ll v = Q[i];
        // deb(v);
        ll o = upper_bound(all(sz), v-1) - sz.begin();

        while (true) {
            // deb(v, o);
            if (tldr[o] < 0) {
                v = v%-tldr[o];
                if (v==0) v -= tldr[o];
                o = upper_bound(all(sz), v-1) - sz.begin();
            } else {
                ll s = seg[tldr[o]].size();
                if (s > sz[o]-v) {
                    ll p = s-1-sz[o]+v;
                    cout<<seg[tldr[o]][p]<<" ";
                    break;
                }
                o--;
            }
        }
    }
    cout<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
