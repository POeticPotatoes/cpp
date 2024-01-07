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

struct vec {
    vll v(3);
    vec (ll a, ll b, ll c) {
        v = {a, b, c};
    }
    vec () {}

    ll &operator [] (ll a) {
        return v[a];
    }

    vec operator + (vec a, vec b) {
        return {a[0]+b[0], a[1]+b[1], a[2] + b[2]};
    }

    vec operator * (vec a, ll b) {
        return {a[0]*b, a[1]*b, a[2]*b}
    }
};

void solve() {
    ll n;
    cin>>n;
    vector<vec> A(n);
    REP(i, n) cin>>A[i][0]>>A[i][1]>>A[i][2];

    REP(i, n) REP(j, n) REP(k, n) {
        
    }
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
