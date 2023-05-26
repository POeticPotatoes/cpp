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

const ll N = 4e5;

ll x, y, m, a, b, A[N]{0, 1, 1};

void solve() {
    cin>>x>>y>>m;
    if (x>y) swap(x, y);
    a = 0;
    if (y>=m) return (void) (cout<<0<<endl);
    if (y<=0) return (void) (cout<<-1<<endl);
    if (x<=0) a = -1*(x/y) + 1;
    x += y*a;
    deb(x, y);

    FORN(i, 1, N) {
        deb(i, A[i-1], A[i], (A[i-1]*x + A[i]*y > m));
        if (A[i-1]*x + A[i]*y >= m) return (void) (cout<<i-1+a<<endl);
        A[i+1] = A[i] + A[i-1];
    }
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
