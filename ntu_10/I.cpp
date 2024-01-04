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
    vll A(n+2), diff;
    FORN(i, 1, n) cin>>A[i];
    FORN(i, 0, n) diff.eb(A[i+1]-A[i]);

    n += 1;
    vll sum(1<<n), DP(1<<n, 1);
    FOR(i, 1, 1<<n) {
        ll p = __builtin_ctz(i);
        sum[i] = sum[i^(1<<p)] + diff[p];
    }

    FOR(i, 1, 1<<n) {
        FOR(j, 0, n) {
            if (i>>j&1) DP[i] = max(DP[i], DP[i^(1<<j)] + !(sum[i]));
        }
    }
    cout<<n+1 - DP[(1<<n)-1]<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
