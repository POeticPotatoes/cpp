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

ll l, r, n, s;

void solve() {
    cin>>l>>r;
    n = log2(r/l)+1;
    deb(l, r, n);
    if (n==1) return (void) (cout<<"1 "<<r-l+1<<endl);
    s = (r>>(n-1))-l+1;
    ll th = max(0LL, (((r>>(n-2))/3)-l+1));
    th = (th * (n-1)) %M;
    deb(s, th);
    s = (s + th) %M;
    cout<<n<<" "<<s<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
