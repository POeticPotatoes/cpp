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

const ll N = 3e6+10;

ll n, M, fac[N], inv[N];

ll modPow(ll a, ll p) {
    if (p==0) return 1;
    ll ans = modPow(a, p/2);
    ans = (ans*ans)%M;
    if (p&1) ans = (ans*a)%M;
    return ans;
}

ll choose(ll a, ll b) { return ((fac[a]*inv[b])%M * inv[a-b])%M; }

void init() {
    fac[0] = 1;
    FOR(i, 1, N) fac[i] = (fac[i-1]*i)%M; 
    inv[N-1] = modPow(fac[N-1], M-2);
    ROF(i, N-1, 0) inv[i-1] = (inv[i]*i)%M;
}

void solve() {
    cin>>n>>M;
    init();
    deb(choose(4,2));

    ll ans[4], x;
    ans[0] = 1;
    ans[1] = (2*fac[2*n]) %M;
    ans[1] = (ans[1]-fac[n]+M) %M;
    ans[1] = (ans[1]-ans[0]+M) %M;

    ans[2] = (2*choose(2*n, n)) %M;
    ans[2] = (ans[2]*fac[n]) %M;
    ans[2] = (ans[2]*fac[2*n]) %M;

    ll c, s;
    s = 0;
    FORN(i, 0, n) {
        c = (choose(n, n-i) * choose(n, i)) %M;
        c = (c*choose(2*n-i, n)) %M;
        c = (c*fac[n]) %M;
        c = (c*fac[n]) %M;
        c = (c*fac[n]) %M;
        s = (s+c) %M;
    }
    ans[2] = (ans[2]-s+M) %M;
    ans[2] = (ans[2]-ans[1]+M) %M;
    ans[2] = (ans[2]-ans[0]+M) %M;

    ans[3] = fac[3*n];
    ans[3] = (ans[3]-ans[2]+M) %M;
    ans[3] = (ans[3]-ans[1]+M) %M;
    ans[3] = (ans[3]-ans[0]+M) %M;
    x = (ans[1] + 2*ans[2] + 3*ans[3]) %M;
    cout<<x<<endl;
}

int main() {
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
