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
    ll n, m, d;
    cin>>n>>m>>d;
    ll s = max(n, m<<1);
    vll A(n), B(s);
    REP(i, n) cin>>A[i];
    REP(i, m) cin>>B[i];
    FOR(i, m, s) B[i] = B[i%m];

    auto check = [&] () {
        ll res = 0;
        REP(i, n) res += A[i]==i+1;
        return res;
    };

    ll ans = check() + (d-1)/2;

    ll t = min(s, d-1);
    REP(i, t) {
        REP(j, B[i]) A[j]++;
        ans = max(ans, check() + (d-i-2)/2);
    }

    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
