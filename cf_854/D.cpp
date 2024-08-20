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

const ll N = 3e5+1;

int n, k, c, j, A[N], C[N], D[N], vis[N];
ll DP[N], s;

void solve() {
    cin>>n>>k;
    FORN(i, 1, n) cin>>A[i];
    FORN(i, 1, k) cin>>C[i];
    FORN(i, 1, k) {
        cin>>c;
        D[i] = C[i] - c;
    }
    s=0, DP[0] = 0;
    memset(vis+1, 0, sizeof(int)*k);
    FORN(i, 1, n) {
        c = A[i], j = vis[c], vis[c] = i, s += C[c], DP[i] = DP[i-1];
        if (c == A[i-1]) {
            s -= D[c];
            continue;
        }
        if (j) DP[i] = max(DP[j+1]+D[c], DP[i]);
    }
    cout<<s-DP[n]<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
