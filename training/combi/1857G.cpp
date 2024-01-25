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
const int M = MOD[3];
const int inf = (int)1e9;
const ll INF = 1e18;

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

void solve() {
    ll n, s;
    cin>>n>>s;
    vector<array<ll, 3>> A(n-1);

    REP(i, n-1) cin>>A[i][1]>>A[i][2]>>A[i][0];
    sort(all(A));

    vll DSU(n+1), SZ(n+1, 1);
    iota(all(DSU), 0);

    function<ll(ll)> parent = [&] (ll v) {
        if (DSU[v] == v) return v;
        return DSU[v] = parent(DSU[v]);
    };

    ll ans=1;
    REP(i, n-1) {
        ll a = parent(A[i][1]), b = parent(A[i][2]);
        assert(a != b);

        ll cnt = (SZ[a] * SZ[b] - 1) % (M-1);
        ans = (modPow(s-A[i][0]+1, cnt) * ans) %M;
        DSU[a] = b;
        SZ[b] += SZ[a];
    }

    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
