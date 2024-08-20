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
constexpr ll N = 2e5;

ll n, A[N], p, l, m;
vector<pair<ll, ll>> ans;

void add(ll x, ll y) {
    assert(x<=y);
    if (x==y) return;
    ans.eb(x, y);
}

void solve() {
    ans.clear();
    cin>>n;
    REP(i, n) cin>>A[i];

    MinHeap<pair<ll,ll>> q;
    p = A[0]&1;

    REP(i, n) if ((A[i]&1) == p)
        q.push({A[i], i});
    m = l = 0;
    while (q.size()) {
        auto r = q.top();
        while (l < r.second) {
            if ((A[l]&1) == p) add(l, r.second);
            else add(m, l);
            l++;
        }
        while (++l<n && (A[l]&1) != p)
            add(q.top().second, l);
        while (q.size() && q.top().second <= l) q.pop();
        m = l;
        deb(l, m, n);
    }
    for (;l<n;l++)
        add(m, l);

    cout<<ans.size()<<endl;
    for (auto i: ans)
        cout<<i.first+1<<" "<<i.second+1<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
