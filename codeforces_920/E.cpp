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

const ll MOD[] = {999727999, 1070777777, 1000000007, 998244353};
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
const int M = MOD[2];
const int inf = (int)1e9;
const ll INF = 1e18;

void solve() {
    ll h, w, a, b, c, d;
    cin>>h>>w>>a>>b>>c>>d;
    if (a>=c) return (void) (cout<<"Draw\n");

    ll m = a + (c-a+1)/2;
    ll s = max(1LL, b - (m-a)),
       t = min(w, b + (m-a)),
       x = max(1LL, d - (c-m)),
       y = min(w, d + (c-m));

    if ((c-a)&1) {
        if (s<=x && t>=y) return (void) (cout<<"Alice\n");
    } else
        if (x<=s && y>=t) return (void) (cout<<"Bob\n");
    cout<<"Draw\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
