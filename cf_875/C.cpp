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

ll n;
pair<ll, ll> A[N];
vv<ll> adj;

ll child(const pair<ll, ll> &p, ll v) { return v==p.first?p.second:p.first; }

ll dfs(ll v, ll p, ll d, ll c) {
    ll ans = c;
    for (auto id: adj[v]) {
        ll ch = child(A[id], v);
        if (ch!=p) ans = max(ans, dfs(ch, v, id, c+(id<d)));
    }
    return ans;
}

void solve() {
    cin>>n;
    adj = vv<ll>(n+1);
    REP(i, n-1) {
        cin>>A[i].first>>A[i].second;
        adj[A[i].first].eb(i);
        adj[A[i].second].eb(i);
    }

    ll ans = dfs(1, -1, 0, 1);
    printf("%lld\n", ans);
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
