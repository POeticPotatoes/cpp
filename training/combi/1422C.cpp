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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

string A;
ll n, ans=0;

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll a = modPow(v, p/2);
    a = (a*a)%M;
    if (p&1) a = (a*v)%M;
    return a;
}

void solve() {
    cin>>A;
    n = A.size();
    ll v = 0, u;

    REP(p, n) {
        ll a = A[n-p-1]-'0', x = n-p-1;
        v = (v + (modPow(10, p-1) * p) %M ) % M;
        u = (modPow(10, p) * (((x*(x+1))>>1)%M))% M;
        ans = (ans + ((v+u)%M * a)%M) %M;
        // deb(p, a, u, v, ans);
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
