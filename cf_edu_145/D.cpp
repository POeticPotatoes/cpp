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

const ll N = 4e5;

string S;

void solve() {
    cin>>S;
    ll n = S.size();
    vll A(n+1), B(n+1);
    A[0] = B[n] = 0;
    FORN(i, 1, n) A[i] = A[i-1] + (S[i-1] == '1');
    ROF(i, n-1, -1) B[i] = B[i+1] + (S[i] == '0');
    ll ans = INF;
    FORN(i, 0, n) {
        ll cur = (1e12+1) * (A[i] + B[i]);
        cur -= (1e12+2) * (i && i<n && S[i-1] == '1' && S[i] == '0');
        ans = min(ans, cur);
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}