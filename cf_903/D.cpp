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

const ll N = 1e6;

bool used[N+1];

vll primes;

void factorize(ll v, map<ll, ll> &m) {
    for (auto p: primes) {
        if (!used[v]) {
            if (v != 1) m[v]++;
            return;
        }
        while (!(v%p)) {
            m[p]++;
            v /= p;
        }
    }
    if (v != 1) m[v]++;
}

void solve() {
    ll n;
    cin>>n;
    vll A(n);
    REP(i, n) cin>>A[i];

    map<ll, ll> sup;
    vector<map<ll, ll>> divisors(n);

    REP(i, n) {
        factorize(A[i], divisors[i]);
        for (auto &[a, b]: divisors[i]) sup[a]+=b;
    }

    map<ll, ll> suggested, deficit;
    for (auto &[a, b]: sup) {
        if (b%n) return (void) (cout<<"NO\n");
        suggested[a] = b/n;
    }

    REP(i, n) {
        for (auto &[a, b]: suggested)
            deficit[a] += divisors[i][a] - b;
    }
    for (auto &[a, b]: deficit) {
        if (b) return (void) (cout<<"NO\n");
    }
    cout<<"YES\n";
}

void init() {
    FORN(i, 2, N) {
        if (used[i]) continue;
        primes.eb(i);
        for (int j=i+i;j<=N;j+=i) used[j] = 1;
    }
}

int main() {
    int t=1;
    init();
    cin >> t;
    while (t--) solve();
}
