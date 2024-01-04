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

const ll N = 2e5;

ll n, m, d, A[N];

void solve() {
    cin>>n>>m>>d;
    FORN(i, 1, m) cin>>A[i];
    A[0] = 1-d;
    A[m+1] = n+1;

    map<ll, ll> ans;
    ll def=0;

    FORN(i, 1, m) {
        def += (A[i]-A[i-1] + d-1)/d;
        ll a = (A[i]-A[i-1] + d-1)/d + (A[i+1]-A[i]-1)/d;
        ll b = (A[i+1]-A[i-1]-1)/d;
        ans[a-b]++;
    }
    def+=(n-A[m])/d;
    auto p = *ans.rbegin();
    cout<<def-p.first<<" "<<p.second<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
