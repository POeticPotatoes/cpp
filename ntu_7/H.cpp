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
    ll n, l, t;
    cin>>n>>l>>t;
    vv<pair<ll, ll>> adj(n+1, vector<pair<ll, ll>>());
    vll A(n+1);
    FORN(i, 1, l) {
        ll a, b;
        cin>>a>>b;
        adj[b].eb(a, i);
    }
    FORN(i, 1, n) cin>>A[i];
    vll ans = A;

    REP(j, 8) {
        MinHeap<pair<ll, ll>> Q;
        vll vis(n+1);
        FORN(i, 1, n) if (A[i]>>j&1) Q.emplace(0, i);

        while (Q.size()) {
            auto [b, a] = Q.top(); Q.pop();
            if (vis[a]) continue;
            vis[a] = b;
            if (b>t) continue;
            ans[a] |= 1<<j;
            for (auto &[c, id]: adj[a]) {
                ll k = id + (b-id+l-1)/l * l;
                Q.emplace(k, c);
            }
        }
    }
    FORN(i, 1, n) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
