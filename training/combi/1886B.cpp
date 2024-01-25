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
    ll n;
    cin>>n;
    vector<pair<ll, ll>> A(n);
    REP(i, n) cin>>A[i].first;
    REP(i, n) cin>>A[i].second;

    ll m;
    cin>>m;
    vector<pair<ll, ll>> B(m);
    REP(i, m) cin>>B[i].first;
    REP(i, m) cin>>B[i].second;

    map<ll, ll> present;
    REP(i, n) present[A[i].first] = A[i].second;

    ll ans=1;
    REP(i, m) {
        auto &[a, b] = B[i];
        if (!present.count(a) || present[a] < b) return (void) (cout<<0<<"\n");
        if (present[a]>b) ans = (ans*2) %M;
        present.erase(a);
    }
    ans = (ans * modPow(2, present.size())) %M;
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
