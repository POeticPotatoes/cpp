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

const ll N =- 2e5;

ll n, a, b, d;
vv<ll> adj;

ll dfs(ll v, ll p) {
    vll sz;
    for (auto c: adj[v]) if (c!=p) sz.eb(dfs(c, v));
    sort(all(sz), greater<ll>());
    sz.eb(0);
    sz.eb(0);

    d = max(d, sz[0]+sz[1]+1);
    return sz[0]+1;
}

void solve() {
    cin>>n;
    adj = vv<ll>(n+1);

    REP(i, n-1) {
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    d = 0;
    d = max(dfs(1, -1), d);
    REP(i, (n-1)>>1) cout<<"1 ";
    if (!(n&1)) cout<<"2 ";
    FORN(i, 1, (n+1)>>1) cout<<min(n, (1+(i<<1) + !(n&1)))<<" ";
    cout<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
