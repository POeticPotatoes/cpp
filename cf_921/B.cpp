#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
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

const ll N = 1e8;

ll P[N+1];
vll primes;

void init() {
    FORN(i, 2, N) if (!P[i]) {
        primes.eb(i);
        for(int j=i;j<=N;j+=i) P[j]=1;
    }
}

void solve() {
    ll x, n;
    cin>>x>>n;

    if (n==1) return (void) (cout<<x<<"\n");

    ll ans=1;
    for (ll i=1;i*i<=x;i++) if (!(x%i)) {
        ll o = x/i;
        if (i>=n) ans=max(ans, o);
        if (o>=n) ans=max(ans, i);
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    // init();
    cin >> t;
    while (t--) solve();
}
