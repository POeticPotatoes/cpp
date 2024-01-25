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
    ll n, k;
    cin>>n>>k;
    vector<pair<ll, ll>> A(n+2);

    FORN(i, 0, n) cin>>A[i].first>>A[i].second;
    A[n+1] = A[0];

    ld raw=0;
    auto dist = [&] (pair<ll, ll> &a, pair<ll, ll> &b) {
        return sqrt((ld) ((a.first-b.first)*(a.first-b.first) 
                    + (a.second-b.second)*(a.second-b.second)));
    };
    FORN(i, 0, n) {
        raw += dist(A[i], A[i+1]);
        deb(raw);
    }
    vector<ld> DP(n+2, INF);
    multiset<ld> window;
    FORN(i, 1, k) {
        DP[i] = dist(A[i-1], A[0]) + dist(A[i], A[0]) - dist(A[i], A[i-1]);
        window.insert(DP[i]);
    }

    FORN(i, k+1, n+1) {
        DP[i] = *(window.begin()) + dist(A[i-1], A[0]) + dist(A[i], A[0]) - dist(A[i], A[i-1]);
        deb(DP[i], *window.begin());
        window.erase(window.find(DP[i-k]));
        window.insert(DP[i]);
    }
    deb(DP);

    ld ans = raw + DP[n+1];
    printf("%.10Lf\n", ans);
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
