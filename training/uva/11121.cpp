#include <bits/stdc++.h>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
const ll MAX = 1ll<<35;

char *p, A[64]{};
ll n, ans, cur, check;

void solve() {
    cin>>n;
    if (!n) return (void) (cout<<0<<endl);

    ans = abs(n);
    for (check=1+(n>0);check<MAX;check<<=2) {
        if (check&ans) ans+=check<<1;
    }
    p = A+63;
    cur = 1;
    REP(i, 63) {
        *--p = 48+!!(cur&ans);
        cur<<=1;
    }
    while (*p==48) p++;
    printf("%s\n", p);
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    REP(i, t) {
        printf("Case #%lld: ", i+1);
        solve();
    }
}
