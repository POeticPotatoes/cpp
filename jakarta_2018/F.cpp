#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;
#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
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
    ll n, m;
    cin>>n>>m;
    vll A(n), B(n), H(n);
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>B[i];
    ll p=0, t=0;
    while (p < n && t + A[p] <= m) {
        t += A[p];
        p++;
    }
    if (!p) return (void) (cout<<"-1\n\n");

    H[p-1] = p-1;
    ROF(i, p-2, -1) {
        if (B[i] > B[H[i+1]]) H[i] = i;
        else H[i] = H[i+1];
    }
    vector<ll> times;
    times.eb(0);
    ll rem = 0, bp=0, total=B[0];
    deb(p, t, A, B, H);

    REP(i, p) {
        rem += A[i];
        while (bp < n && rem >= B[times[bp]]) {
            rem -= B[times[bp]];
            bp++;
            if (bp==times.size()) {
                times.eb(times.back()+1);
                total += B[times.back()];
            }
        }
        if (bp == n) break;
        while (times.back() < H[times[bp]]) times.eb(times.back()+1);
        times.eb(times.back());
        total += B[times.back()];
        deb(times);
        if (total > m) break;
    }
    if (total<m) return (void) (cout<<"-1\n\n");
    ll p2=0, t2=0;
    vll ans;
    while (p2<times.size()) {
        t2 += B[times[p2]];
        p2++;
        if (t2 > m) break;
        if (times[p2] == times[p2-1]) ans.eb(t2);
    }
    cout<<ans.size()<<"\n";
    for (auto c: ans) cout<<c<<" ";
    cout<<"\n";
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
