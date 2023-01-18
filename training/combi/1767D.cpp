#include <bits/stdc++.h>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll i = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
typedef long long ll;
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
constexpr ll N = 20;

ll n, l, r, ld, rd;
char s[N];

void solve() {
    scanf("%lld", &n);
    scanf("%s", s);
    l = 1, r = 1<<n, ld=rd=1;
    REP(i, n) {
        if (s[i]=='1') {
            l+=ld;
            ld<<=1;
        } else {
            r-=rd;
            rd<<=1;
        }
    }
    for (ll i=l;i<=r;i++) printf("%lld ", i);
    printf("\n");
}

int main() {
    IO;
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
