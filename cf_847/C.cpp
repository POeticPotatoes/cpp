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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 200;

ll n, vis[N], P[N], c;
vll A[N];

void solve() {
    cin>>n;
    REP(i, n) {
        A[i] = vll(n);
        REP(j, n-1) cin>>A[i][j];
    }
    deb(n);
    memset(P, 0, sizeof(ll)*n);
    vll ans;
    REP(i, n) {
        memset(vis, 0, sizeof(ll)*(n+1));
        REP(j, n) {
            deb(i, j, A[j][P[j]], P[j]);
            if (vis[A[j][P[j]]]++) {
                c = A[j][P[j]];
                break;
            }
        }
        REP(j, n) P[j] += A[j][P[j]] ==c;
        ans.eb(c);
    }
    REP(i, n) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
