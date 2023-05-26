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

const ll N = 2e5;

ll n, m, A[N], B[N];

bool check(int k) {
    int c = 0, u = 0;
    bitset<N> vis;
    ROF(i, k, -1) {
        // deb(i, c, u, A[i]);
        if (A[i]<0 || vis[A[i]]) {
            u = max(0, u-1);
            continue;
        }
        // deb(B[A[i]], i-u);
        if (B[A[i]] > i-u) return false;
        u += B[A[i]];
        vis[A[i]] = 1;
        if (++c == m) return true;
    }
    return false;
}

void solve() {
    cin>>n>>m;
    REP(i, n) {
        cin>>A[i];
        A[i]--;
    }
    REP(i, m) cin>>B[i];
    if (!check(n-1)) return (void) (cout<<-1<<endl);
    int l = 0, r = n-1;
    while (l<r) {
        int mid = (l+r)/2;
        // deb(l, r, mid);
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    cout<<r+1<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
