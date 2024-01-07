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
    ll n, q;
    cin>>n>>q;
    vv<ll> adj(n+1);
    REP(i, n-1) {
        ll a, b;
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }

    vll C(n+1);
    ll ans, k, low;
    function<ll(ll,ll,ll)> dfs = [&](ll v, ll p, ll d) {
        deb(v, p, d);
        ll s = C[v];
        for (auto c: adj[v]) if (c!=p)
            s += dfs(c, v, d+1);
        if (s>=k) {
            if (d>low) {
                low=d;
                ans=0;
            }
            ans+=d==low;
        }
        return s;
    };
    deb("INIT!");

    REP(i, q) {
        ll m;
        cin>>k>>m;
        vll Q(m);
        REP(j, m) cin>>Q[j];
        REP(j, m) C[Q[j]]=1;
        ans=0, low=0;
        dfs(1, 0, 0);
        REP(j, m) C[Q[j]]=0;
        cout<<ans<<"\n";
    }
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
