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

const ll N = 24;

void solve() {
    ll n;
    cin>>n;
    vll A(n), DP(1<<N);
    REP(i, n) {
        string s;
        cin>>s;
        REP(j, 3) A[i] |= 1<<(s[j]-'a');
    }

    ll mask = (1<<N)-1;
    REP(i, n) {
        ll b = __builtin_popcountll(A[i]);
        REP(j, N) if ((A[i]>>j)&1) {
            DP[mask^(1<<j)]++;
            if (b==3) DP[mask^A[i]^(1<<j)]--;
        }
        if (b==3) DP[mask^A[i]]++;
        if (b==2) DP[mask^A[i]]--;
    }

    REP(j, N) REP(i, 1<<N) if (!((i>>j)&1))
        DP[i] += DP[i|(1<<j)];

    ll ans=0;
    REP(i, 1<<N)
        ans ^= DP[i]*DP[i];
    cout<<ans<<"\n";
}

int main() {
    IO;
    int t=1;
    // cin >> t;
    while (t--) solve();
}
