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

const ll N = 3e5;

ll n, A[N], B[N], S[N], E[N], C[N];

void solve() {
    cin>>n;
    FORN(i, 1, n) cin>>A[i];
    FORN(i, 1, n) cin>>B[i];
    FORN(i, 1, n) S[i] = S[i-1]+B[i];
    memset(C, 0, sizeof(ll)*(n+1));
    memset(E, 0, sizeof(ll)*(n+1));

    FORN(i, 1, n) {
        ll k = A[i]+S[i-1];
        ll p = upper_bound(S, S+n+1, k) - S;
        deb(i, A[i], p, k);
        ll v = k-S[p];
        E[p] += v;
        C[p]++;
    }
    ll s=0, v=1;
    FORN(i, 1, n) {
        s = E[i];
        ll t = v*B[i];
        cout<<t+s<<" ";
        // deb(i, s, v, t);
        v -= C[i];
        v++;
    }
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
