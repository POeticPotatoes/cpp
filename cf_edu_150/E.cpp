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

const ll N = 3e5;

ll n, c, k;
pair<ll, ll> A[N];

void solve() {
    cin>>n;
    REP(i, n) {
        cin>>c;
        A[i] = {c, i};
    }
    cin>>k;
    sort(A, A+n, greater<pair<ll, ll>>());
    map<pair<ll, ll>, ll> V;
    map<ll, ll, greater<ll>> S;
    V.emplace(make_pair(0, n-1), n);
    REP(i, n) {
        auto &[h, v] = A[i];
        auto p = V.upper_bound({v, INF});
        auto [a, b] = *--p;
        S[a.second - a.first + 1] += b-h;
        V.erase(p);
        if (a.first<v) V.emplace(make_pair(a.first, v-1), h);
        if (v<a.second) V.emplace(make_pair(v+1, a.second), h);
    }
    ll ans = 0;
    for (auto &[v, o]: S) {
        ll r = min(o, (k+v-1)/v), s = min(k, r*v);
        ans += s-r;
        k -= s;
        if (!k) break;
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
