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

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

void solve() {
    ll n, m;
    cin>>n>>m;
    vll A(n);
    vector<pair<ll, ll>> B;
    REP(i, n) cin>>A[i];
    sort(all(A));
    ll cnt=1;
    FOR(i, 1, n) {
        if (A[i] == A[i-1]) {
            cnt++;
            continue;
        }
        B.eb(A[i-1], cnt);
        cnt = 1;
    }
    B.eb(A[n-1], cnt);
    ll b = B.size();

    if (b < m)
        return (void) (cout<<"0\n");
    ll cur=1, l=0, ans=0;

    REP(i, m-1) cur = (cur * B[i].second) %M;

    FOR(i, m-1, b) {
        cur = (cur * B[i].second) %M;
        while (B[i].first - B[l].first >= m)
            cur = (cur * modPow(B[l++].second, M-2)) %M;
        if (i-l+1 == m) ans = (ans + cur) %M;
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
