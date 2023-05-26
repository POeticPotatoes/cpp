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

ll n;

void solve() {
    cin>>n;
    vector<string> A(n);
    REP(i, n) cin>>A[i];

    vector<unordered_map<int, ll>> B(26);
    REP(i, n) {
        int cur = 0, all=0;
        for (char c : A[i]) cur ^= 1<<(c-'a'), all |= 1<<(c-'a');
        REP(j, 26)
            if (!(all&(1<<j))) {
                B[j][cur]++;
            }
    }
    ll ans = 0;
    REP(k, 26) {
        for (auto [cur, count]: B[k]) {
            int inv = cur ^ ((1<<26)-1) ^ (1<<k);
            if (B[k].count(inv)) ans += count*B[k][inv];
        }
    }
    cout<<ans/2<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
