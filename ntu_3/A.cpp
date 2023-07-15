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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 700;

ll m, t, r, A[N], D[N]{}, C[N]{};

void solve() {
    cin>>m>>t>>r;
    ll v;
    REP(i, m) {
        cin>>v;
        A[v] = 1;
    }

    ll c = 0, ans = 0;;
    FOR(i, 1, N) {
        c -= C[i];
        if (!A[i] || c>= r) continue;
        ll j = 1;
        while (c < r) {
            if (j>=i || j>t) break;
            if (D[i-j]) continue;
            D[i-j] = 1;
            C[i-j+t+1] = 1;
            c++, j++, ans++;
        }
        if (c<r) return (void) (cout<<-1<<endl);
    }
    cout<<"A: "; REP(i, 20) cout<<A[i]<<" ";
    cout<<endl;
    cout<<"C: "; REP(i, 20) cout<<C[i]<<" ";
    cout<<endl;
    cout<<"D: "; REP(i, 20) cout<<D[i]<<" ";
    cout<<endl;
    cout<<ans<<endl;
}

int main() {
    int _=1;
    // cin >> t; // Comment this out if there are no tests
    while (_--) solve();
}
