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

constexpr ll M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

ll n, a, b, ans;


void solve() {
    cin>>n;
    vector<vector<ll>> adj(n+1);
    ans=0;
    for (ll i=1;i<n;i++) {
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    function<ll(ll, ll)> dfs = [&](ll v, ll p) {
        ll d=0;
        for (auto i: adj[v]) {
            if (i == p) continue;
            d = max(d, dfs(i, v));
        }
        deb(v, d);
        ans += (++d);
        return d;
    };

    dfs(1, 0);
    ans %= M;
    ans = (ans*modPow(2, n-1)) %M;
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
