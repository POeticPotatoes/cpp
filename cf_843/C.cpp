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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll n, x, a, c, orig, m, fin;

void solve() {
    cin>>n>>x;
    orig = n, fin = x;
    for (ll p=1LL<<62;p>0;p>>=1) {
        if (x&p && !(n&p))
            return (void) (cout<<-1<<endl);
        if (n&p) {
            if (x&p) {
                n -= p;
                x -= p;
                deb(n, x);
                continue;
            }
            a = p;
            break;
        }
    }
    if (!n && !x) return (void) (cout<<orig<<endl);
    deb(a);
    for (ll p=a>>1;p>0;p>>=1)
        if (x&p) return (void) (cout<<-1<<endl);
    a<<=1;
    m = orig + a-n;
    if ((m&orig) != fin) return (void) (cout<<-1<<endl);
    cout<<m<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
