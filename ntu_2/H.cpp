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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 4e3;

ll n, k, W[N], P[N]{}, ans, DP[N][N];
vll A[N];

void ins(int v, int d) {
    // deb(v, d);
    FORN(i, 0, k) {
        DP[d][i] = 0;
        if (W[v]<=i) {
            DP[d][i] = DP[d-1][i-W[v]];
            DP[d][i] += P[v];
        }
        DP[d][i] = max(DP[d][i], DP[d-1][i]);
    }
    // FORN(i, 0, k) printf("%2lld ", DP[d][i]);
    // printf("\n");
}

void CDQ(int l, int r, int d) {
    // deb(l, r, d);
    if (l==r) {
        ll c=0, v=0;
        ans = max(ans, DP[d][k]);
        for(int i=1; i<=W[l] && i<=k;i++) {
            v += A[l][i-1];
            // deb(c, v, DP[d][k-i]);
            ans = max(ans, DP[d][k-i] + v);
        }
        // deb(ans);
        return;
    }
    int m = (l+r)/2, p=d;
    for (int i=l;i<=m;i++) ins(i, ++p);
    // deb(m);
    CDQ(m+1, r, p);
    for (int i=m+1;i<=r;i++) ins(i, ++d);
    CDQ(l, m, d);
}

void solve() {
    cin>>n>>k;
    REP(i, n) {
        cin>>W[i];
        A[i].resize(W[i]);
        REP(j, W[i]) {
            cin>>A[i][j];
            P[i] += A[i][j];
        }
    }
    CDQ(0, n-1, 0);
    cout<<ans<<endl;
}

int main() {
    IO;
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
