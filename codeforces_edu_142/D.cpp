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

ll n, m;

struct node {
    map<ll, node> v;

    int check(vll &p, int cur) {
        if (cur>=m || !(v.count(p[cur]))) return cur;
        //deb(cur, m);
        return v[p[cur]].check(p, cur+1);
    }

    void build(vll &p, int val) {
        if (val > m) return;
        int i=0;
        for (;p[i]!=val;i++);
        v[++i].build(p, val+1);
    }
};

node orig;

void solve() {
    orig = node();
    cin>>n>>m;
    vv<ll> A(n, vll(m));
    REP(i, n) REP(j, m) cin>>A[i][j];

    REP(i, n) orig.build(A[i], 1);
    REP(i, n)
        cout<<orig.check(A[i], 0)<<(i==n-1?"":" ");
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
