#include <bits/stdc++.h>
using namespace std;

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
constexpr ll N = 105;

ll n, A[N]{}, B[N]{}, DP[N][N]{}, S[N][N]{}, P[N]{}, ans, c;
vll F[N];
bool flag;

// you can do this.
void solve() {
    flag=ans=0;
    scanf("%lld", &n);
    REP(i, N) A[i] = i;
    FORN(i, 1, n) {
        scanf("%lld", &c);
        flag &= c==1;
        FORN(j, i+1, n) {
            scanf("%lld", &c);
            if (c==1) A[j] = A[i];
            if (c==2) P[j] = i;
        }
    }
    
    DP[0][0] = 1;
    FORN(i, 1, n) {
        FORN(j, 0, n) 
            DP[i][j] = DP[i-1][j];
        if (A[i] != A[i-1]) FOR(j, 0, n)
            DP[i][j+1] = (DP[i][j+1]+DP[i-1][j])%MOD;
        if (P[i].empty()) continue;
    }
    FORN(i, 0, n)
        ans = (ans+DP[n][i])%MOD;
    printf("%lld\n", ans);
}

int main() {
    int t=1;
    REP(i, n) A[i] = i;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
