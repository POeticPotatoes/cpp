#include <bits/stdc++.h>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll i = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 1, n)
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

constexpr int MOD = 998244353;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 2e5;

int n, A[N], B[N], vis[N], e, v, l;
ll ans;
vector<int> P[N];

void dfs(int k) {
    if (vis[k]) return;
    vis[k] = 1;
    v++;
    for (auto i: P[k]) {
        e++;
        dfs(i);
        l += i==k;
    }
}

void solve() {
    ans=1;
    cin>>n;
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>B[i];
    REP(i, n) P[i].clear();
    REP(i, n) {
        P[A[i]].eb(B[i]);
        P[B[i]].eb(A[i]);
    }

    memset(vis+1, 0, sizeof(ll)*n);
    REP(i, n) {
        if (vis[i]) continue;
        e = v = l =0;
        dfs(i);
        if (e != 2*v) return (void) (cout<<0<<endl);
        if (l) {
            assert(l==2);
            REP(j, l/2) ans = ans*n%MOD;
        }
        else ans = ans*2%MOD;
    }
    cout<<ans<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
