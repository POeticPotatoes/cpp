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

constexpr int M = 998244353;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 4e5;

ll n, A[N][3], ans;

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

void solve() {
    cin>>n;
    n /= 3;
    REP(i, n) REP(j, 3) cin>>A[i][j];
    ans = 1;
    REP(i, n) {
        ll c = 1, s=A[i][0]+A[i][1]+A[i][2], m=0;
        REP(j, 3) {
            if (m < s-A[i][j]) {
                m = s-A[i][j];
                c=1;
            } else c += m == s-A[i][j];
        }
        deb(i, c);
        ans = (ans*c) %M;
    }
    for (int i=n/2+1;i<=n;i++) ans = (ans*i) %M;
    ll d=1;
    for (int i=1;i<=n/2;i++) d = (d*i) %M;
    ans = (ans * modPow(d, M-2)) %M;
    cout<<ans<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
