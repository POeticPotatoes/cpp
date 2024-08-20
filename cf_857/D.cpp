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

const ll N = 6e5;

ll n;
pair<ll, ll> A[N];

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i].first>>A[i].second;
    sort(A, A+n, [](auto &left, auto &right) {
        return left.first==right.first?left.second<right.second:left.first>right.first;
    });
    multiset<ll> B;
    ll mx = 0;
    REP(i, n) B.emplace(A[i].second);
    ll ans = INF;
    FOR(i, 0, n) {
        auto &[a, b] = A[i];
        B.erase(B.find(b));
        if (i) ans = min(ans, abs(a-mx));
        if (!ans || mx > a) break;
        // bin search for best match
        auto p = B.lower_bound(a);
        if (p != B.end()) 
            ans = min(ans, *p-a);
        if (p != B.begin())
            ans = min(ans, a-*--p);

        // remove item and update mx
        mx = max(mx, A[i].second);
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    IO;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
