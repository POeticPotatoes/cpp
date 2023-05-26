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

const ll N = 5e3;

ll n;
pair<ld, ld> A[N];
ld ans=inf;

pair<ld, ld> operator - (const pair<ld, ld> &a, const pair<ld, ld> &b) {
    return {a.first-b.first, a.second-b.second}; }

ld len(pair<ld, ld> a) {
    return sqrt(a.first * a.first + a.second * a.second); }

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i].first>>A[i].second;
    REP(i, n) {
        auto &a = A[(i-1+n)%n], 
             &b = A[i], 
             &c = A[(i+1)%n];
        pair<ld, ld> x = b-a, y = c-a;
        ld cross = abs(x.first*y.second - x.second*y.first),
           d = cross/len(c-a);
        ans = min(ans, d/2);
    }
    printf("%.10LF\n", ans);
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
