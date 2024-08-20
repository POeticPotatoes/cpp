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

const ll N = 200;

ll n, A[N];

void solve() {
    cin>>n;
    FORN(i, 1, n) cin>>A[i];
    ll o = 0, d=A[1], p=1;
    FORN(i, 1, n) {
        o+=A[i]==1;
        if (A[i] < d) d=A[i], p=i;
    }
    if (o) return (void) (cout<<(o==n?"0\n":"-1\n"));
    vector<pair<ll, ll>> ans;
    FORN(i, 1, n) {
        if (i==p) continue;
        while (A[i] > d) {
            ans.emplace_back(i, p);
            A[i] = (A[i]+d-1)/d;
        }
        if (A[i] < d) d = A[i], p = i, i=0;
    }
    cout<<ans.size()<<endl;
    for (auto [a, b]: ans) printf("%lld %lld\n", a, b);
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
