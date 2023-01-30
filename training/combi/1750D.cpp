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
 
constexpr int MOD = 998244353;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
const ll N = 3e5;
 
ll n, m, A[N], ans, c, x, res, e, cei;
 
void solve() {
    cin>>n>>m;
    REP(i, n) cin>>A[i];
 
    vll fac;
    c = A[0];
    // Prime factorise A[0]
    for (ll i=2;i*i<=c;i++) if (!(c%i)) {
        while (!(c%i)) c/=i;
        fac.eb(i);
    }
    if (c>1) fac.eb(c);
 
    ans = 1;
    FOR(i, 1, n) {
        // S will store non-square-containing factors of x
        // Additionally, the number of primes that consist them
        vector<pair<ll, ll>> S;
        vll F;
        if (A[i-1]%A[i]) return (void) (cout<<0<<endl);
        
        // Get all prime factors of x (fast)
        x = A[i-1]/A[i];
        for (auto j: fac) if (!(x%j)) F.eb(j);
        cei = res = m/A[i];
 
        // Generate all factors of x without squares
        // At the same time modify res
        for (auto j: F) {
            e = S.size();
            REP(k, e) {
                auto p = S[k];
                c = p.first*j;
                res -= (1-2*(p.second&1)) * cei/c;
                S.eb(c, p.second+1);
            }
            S.eb(j, 1);
            res -= cei/j;
        }
        ans = (ans * res) % MOD;
    }
    cout<<ans<<endl;
}
 
int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
