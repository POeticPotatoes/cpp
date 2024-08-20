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
const ll N = 2e5;

ll n, m, d, ans, A[N], B[N], a, b, s;

void solve() {
    cin>>n>>m>>d;
    REP(i, n) cin>>A[i];
    REP(i, m) cin>>B[i];
    a=b=s=0, ans=inf;
    bool flag=false;
    while (b<m && a<n) {
        while (A[a] != B[b]) {
            a++;
            s++;
            if (a==n) {
                cout<<"0\n";
                return;
            }
        }
        if (b) {
            ans = min(ans, s);
            if (d<n-1) ans = min(ans, d-s+1);
            flag |= s>d;
        }
        deb(a, b, s, d, ans);
        b++, s=0;
    }
    if (flag || a==n) {
        cout<<"0\n";
        return;
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
