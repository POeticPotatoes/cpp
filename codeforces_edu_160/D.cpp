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
const int M = MOD[3];
const int inf = (int)1e9;
const ll INF = 1e18;

void solve() {
    ll n;
    cin>>n;
    vll A(n+1), DP(n+1), PREF(n+1);
    FORN(i, 1, n) cin>>A[i];

    stack<ll> chain, sum;

    FORN(i, 1, n) {
        while (chain.size() && A[chain.top()] > A[i]) {
            chain.pop();
            sum.pop();
        }
        ll p = chain.size()?chain.top():0;
        DP[i] = (PREF[i-1] - PREF[p]+M)%M;
        if (chain.size()) {
            DP[i] = (DP[i] + sum.top()) %M;
            sum.push((DP[i] + sum.top()) %M);
        } else {
            DP[i] = (DP[i]+1) %M;
            sum.push(DP[i]);
        }
        deb(DP);
        chain.push(i);
        PREF[i] = (PREF[i-1]+DP[i]) %M;
    }
    deb(DP);

    ll m=INF, ans=0;
    ROF(i, n, 0) {
        if (m<A[i]) continue;
        ans = (ans+DP[i]) %M;
        m=A[i];
    }

    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
