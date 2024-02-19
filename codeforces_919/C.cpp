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

int P[200001];

vll primes;

void solve() {
    ll n;
    cin>>n;
    vector<ll> A(n), valid(n+1);
    REP(i, n) cin>>A[i];
    if (n==1) return (void) (cout<<1<<"\n");

    vector<ll> div(1, 1);
    for (auto p: primes) {
        if (p*2>n) break;
        if (!(n%p)) div.eb(p);
    }

    deb(div);

    auto check = [&] (ll d) {
        deb(d);
        ll diff = abs(A[0] - A[d]);
        if (diff == 1) return false;
        REP(i, d) {
            for (ll j=i+d;j<n;j+=d) {
                ll cur = abs(A[j] - A[j-d]);
                if (diff != cur) {
                    diff = gcd(diff, cur);
                    if (diff==1) return false;
                }
            }
        }
        for (ll i=d;i<=n;i+=d) valid[i] = 1;
        deb("!");
        return true;
    };

    for (auto d: div) {
        check(d);
    }

    ll ans=0;
    valid[n] = 1;
    FORN(i, 1, n) {
        if (!(n%i) && valid[i]) ans++;
    }
    cout<<ans<<"\n";
}

void init() {
    FORN(i, 2, 200000) if (!P[i]) {
        primes.eb(i);
        for (int j=i+i;j<=200000;j+=i) P[j] = 1;
    }
    REP(i, 10) {
        deb(i, primes[i]);
    }
}

int main() {
    IO;
    init();
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
