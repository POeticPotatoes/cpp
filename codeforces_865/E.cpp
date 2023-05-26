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

const ll N = 3000;

ll n, m, a, b, vis[N];
vv<ll> adj;


void solve() {
    cin>>n>>m;
    adj = vv<ll>(n+1);
    REP(i, m) {
        cin>>a>>b;
        if (a==1) continue;
        adj[b].eb(a);
    }
    if (n==1) return (void)  (cout<<"FINITE\n1\n1\n");
    vll q;
    vv<ll> A; 
    q.eb(1);
    memset(vis, 0, sizeof(ll)*(n+1));
    while (q.size()) {
        vll B;
        for (auto i: q) {
            for (auto c: adj[i]) if (!vis[c]) {
                vis[c] = 1;
                B.eb(c);
            }
        }
        A.eb(q);
        q = B;
    }
    FORN(i, 2, n) if (!vis[i]) return (void) (cout<<"INFINITE\n");
    cout<<"FINITE\n";
    vll ans;
    REP(i, A.size())
        for (int j=A.size();j-->i;) for (auto k: A[j])
            ans.eb(k);
    cout<<ans.size()<<endl;
    for (auto i: ans) cout<<i<<" ";
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
