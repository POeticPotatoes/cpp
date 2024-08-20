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
    ll n;
    cin>>n;
    vll A(n);
    REP(i, n) cin>>A[i];

    vv<ll> adj(n<<1);

    REP(i, n) {
        FOR(j, 0, i) {
            if (j+A[j]>=i && j+A[j]<i+A[i]) {
                adj[j+n].eb(i+n);
            }
            if (j+A[i]>=i && j-A[j]<i-A[i]) {
                adj[j].eb(i);
            }
            if (j+A[i]+A[j]-1>=i) {
                if (j+A[j]-1<=i) adj[j+n].eb(i);
                else if (i-A[i]+1<j && j+A[j]-1>i) adj[i].eb(j+n);
            }
            if (j==i-1) {
                adj[j].eb(i+n);
            }
        }
    }

    vll vis(n<<1);
    queue<ll> Q;
    vis[n]=1;
    Q.push(n);
    REP(i, n) if (A[i]>i) {
        vis[i]=1;
        Q.push(i);
    }

    while (Q.size()) {
        ll v = Q.front(); Q.pop();
        for (auto c: adj[v]) if (!vis[c]) {
            deb(v, c);
            vis[c] = vis[v]+1;
            Q.push(c);
        }
    }


    deb(A);
    deb(adj);
    deb(vis);
    ll ans = vis[n-1];
    REP(i, n) if (A[i]+i>=n) {
        ans = min(ans, vis[i+n]);
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
