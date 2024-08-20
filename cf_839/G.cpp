#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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
constexpr ll N = 3e5;

ll n, x, y, A[N], ans, inc, pos;

void solve() {
    cin>>n>>x>>y;
    REP(i, n) cin>>A[i];
    ans=0;

    sort(A, A+n);
    ll *p = lower_bound(A, A+n, x);
    pos = (p-A);

    x += pos;
    // stage 1: increase until not possible
    while (pos<n) {
        if (A[pos] > x) break;
        x++, pos++;
        if (x>=y) return (void) (cout<<pos-(x-y)<<endl);
    }
    if (x>=y) return (void) (cout<<pos-(x-y)<<endl);
    ans = pos;

    inc = (2*(pos)-n);
    while (pos<n) {
        if (A[pos] > y) {
            if (inc<=0) return (void) (cout<<-1<<endl);
            ll v = (y-x+inc-1)/inc;
            ans += v*n;
            x += v*inc;
            cout<<ans-(x-y)<<endl;
            return;
        }
        if (A[pos] > x) {
            if (inc<=0) return (void) (cout<<-1<<endl);
            ll v = (A[pos]-x+inc-1)/inc;
            ans += v*n;
            x += v*inc;
        }
        if (x>=y) return (void) (cout<<ans-(x-y)<<endl);
        ans++, x++, inc+=2, pos++;
    }
    ll v = (y-x+n-1)/n;
    ans += v*n;
    x += v*inc;
    cout<<ans-(x-y)<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
