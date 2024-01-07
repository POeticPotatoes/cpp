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
    ll n, m, k;
    cin>>n>>m>>k;

    vv<ll> adj(n+1);
    vll A(n+1), O(n+1);
    FORN(i, 1, n) cin>>A[i];
    vll vis = A;
    
    REP(i, m) {
        ll a, b;
        cin>>a>>b;
        adj[a].eb(b);
    }

    iota(next(O.begin()), O.end(), 1);
    sort(next(O.begin()), O.end(), [&] (ll a, ll b) {
        return A[a] < A[b];
    });

    ll ans = 0, h = 0;
    FORN(i, 1, n) {
        h = max(h, vis[i]);
        for (auto c: adj[i]) {
            deb(i, c, vis[c], vis[i], ((A[c] - A[i] + k) %k));
            vis[c] = max(vis[c], vis[i] + ((A[c] - A[i] + k) %k));
        }
    }
    ans = h - A[O[1]];
    deb(ans, vis, O);

    FOR(i, 1, n) {
        queue<ll> Q;
        vis[O[i]] = max(vis[O[i]], A[O[i]] + k);
        Q.push(O[i]);
        while (Q.size()) {
            auto v = Q.front(); Q.pop();
            deb(i, v, vis[v]);
            h = max(h, vis[v]);
            for (auto c: adj[v]) {
                ll p = vis[v] + ((A[c] - A[v]+k)%k);
                if (p > vis[c]) {
                    Q.push(c);
                    vis[c] = p;
                }
            }
        }
        ans = min(ans, h-A[O[i+1]]);
        deb(ans);
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
