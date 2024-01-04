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
    cin>>n;
    vll A(n+1);
    FORN(i, 1, n) cin>>A[i];

    cin>>q;
    vector<pair<ll, ll>> Q(q);
    REP(i, q) cin>>Q[i].first>>Q[i].second;
    vv<ll> bits(n+1, vll(31));
    FORN(i, 1, n) {
        REP(j, 31) bits[i][j] = bits[i-1][j] + (A[i]>>j&1);
    }
    deb(bits);

    auto check = [&] (ll l, ll r){
        ll res=0, d=r-l+1;
        REP(i, 31) {
            res |= (bits[r][i]-bits[l-1][i]==d)<<i;
        }
        deb("check", l, r, res);
        return res;
    };

    vll ans(q);
    REP(i, q) {
        ll v=Q[i].second,
           lef=Q[i].first, l=lef, r=n+1;
        if (A[lef]<v) {
            ans[i]=-1;
            continue;
        }
        while (l<r) {
            ll mid = (l+r)>>1;
            if (check(lef, mid) < v) r=mid;
            else l=mid+1;
        }
        ans[i] = l-1;
    }
    REP(i, q) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
