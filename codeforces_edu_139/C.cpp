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
string A[2];

bool check(ll p) {
    for (int i=0;i<n;i++) {
        if (A[p][i]) {
            //deb(i-1, m);
            return (i-1==m);
        }
        if (!A[p^1][i])
            p ^=1;
    }
    return true;
}

void solve() {
    cin>>n>>A[0]>>A[1];
    m=-1;
    REP(i, n) {
        A[0][i] -= 'B', A[1][i] -= 'B';
        if (!A[0][i] || !A[1][i]) m = i;
    }
    //deb(m, (int) A[0][0], (int) A[0][1]);
    if (check(0) || check(1))
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
