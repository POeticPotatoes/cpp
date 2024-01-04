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
    ll w;
    cin>>w;
    vector<ll> A;
    vv<ll> adj;

    function<int()> build = [&]() {
        ll m, n, p = A.size();
        cin>>m>>n;

        A.eb(m); 
        adj.eb(vll());
        REP(i, n) {
            ll k = build();
            adj[p].eb(k);
        }
        return p;
    };

    build();

    ll ans=0;
    function<int(ll)> dfs = [&](ll v) {
        vll kids;
        for (auto c: adj[v]) kids.eb(dfs(c));
        sort(all(kids));
        ll sum = accumulate(all(kids), 0);
        while (sum>w) {
            ans++;
            sum -= kids.back();
            kids.pop_back();
        }

        ans += (sum+A[v])/w;
        return (sum+A[v])%w;
    };

    ans += dfs(0)>0;

    cout<<ans<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
