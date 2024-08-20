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

constexpr int MOD = 998244353;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
const ll N = 70;

ll n, fac[N], inv[N], m;

ll modPow(ll a, ll p) {
    if (p==0) return 1;
    ll ans = modPow(a, p/2);
    ans = (ans*ans) %MOD;
    if (p&1) ans = (ans*a) %MOD;
    return ans;
}

ll choose(ll a, ll b) {
    deb(a, b);
    deb(((fac[a] * inv[b]) %MOD * inv[a-b]) %MOD); 
    return ((fac[a] * inv[b]) %MOD * inv[a-b]) %MOD; 
}

void init() {
    fac[0] = 1;
    FOR(i, 1, N) fac[i] = (fac[i-1]*i) %MOD;
    inv[N-1] = modPow(fac[N-1], MOD-2);
    ROF(i, N-1, 0) inv[i-1] = (inv[i]*i) %MOD;
}

void solve() {
    cin>>n;
    ll a=0, b, c=1;
    b = choose(n, n/2);
    m = (n-2)/4;
    FORN(i, 0, m) a = (a+ choose((n-(4*i+1)), (n/2 - (2*i+1)))) %MOD;
    deb(a);
    if (n>=6) {
        m = (n-6)/4;
        FORN(i, 0, m) a = (a+ choose((n-(4*(i+1))), (n/2 - (2*i+3)))) %MOD;
    }
    deb(a, b, c);
    b = (b-a-c+MOD) %MOD;
    printf("%lld %lld %lld\n", a, b, c);
}

int main() {
    init();
    // deb(choose(4, 2));
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
