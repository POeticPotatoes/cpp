#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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
constexpr ll N = 1e7;

int n, p, A[200], d, c, e;
ll l, r, m;
bool res;

bool check(set<int> &vis, int x, int y, bool loop) {
    deb(x, y, loop);
    FORN(i, x, y) {
        if (loop && i==d) continue;
        if (!vis.count(i)) return false;
    }
    return true;
}

void solve() {
    cin>>n>>p;
    REP(i, n) cin>>A[i];
    set<int> vis;

    c = 0, e = A[n-1];
    REP(i, n)
        vis.insert(A[i]);

    if (vis.size() == p) return (void) (cout<<0<<endl);
    d = 1;
    ROF(i, n-2, -1) if (A[i]!=p-1) {
        d = A[i]+1;
        break;
    }
    deb(c, e, d);

    // binary search
    l = 0, r = p-1;
    while (l<r) {
        m = (l+r)/2;
        if (m+e >=p)
            res = check(vis, (m+e)%p+1, e-1, 1);
        else
            res = check(vis, 0, e-1, 0) && check(vis, m+e+1, p-1, 0);
        if (res)
            r = m;
        else l = m+1;
    }
    cout<<l<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
