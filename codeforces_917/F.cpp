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
    ll n, d;
    cin>>n>>d;
    vll A(n);
    REP(i, n) cin>>A[i];
    sort(all(A), greater<ll>());

    vector<bitset<2001>> DP(n+1), subsets(d+1);

    // Standard knapsack
    DP[0][0] = 1;
    subsets[0][0] = 1;
    ll sum=0;
    REP(i, n) {
        DP[i+1] = DP[i]<<A[i]|DP[i];
        sum += A[i];
    }

    if (sum == d) return (void) (cout<<"YES\n");
    // else some item(s) must be excluded from the subset

    ROF(i, n-1, -1) {

        // exclude current item from sum
        sum -= A[i];

        // only check if current sum is already smaller than d
        if (sum <= d) {
            // find some subset sum that is reachable with remaining elements
            FORN(j, 0, sum) if (DP[i][j]) {
                // get minimum value that must be included to subset sum
                ll l = max(0LL, A[i]-j);

                // get max value that can be included to subset sum (such that right side is still >= A[i])
                ll r = d - A[i] - j;

                if (l>r) continue;
                deb(i, A[i],j,l, r);

                // check if such a subset exists in elements that will be used to produce a length of d
                if ((subsets[d-sum]>>l<<2000-r+l).any()) {
                    cout<<"YES\n";
                    return;
                }
            }
        }

        for (int j=d;j>=A[i];j--)
            subsets[j] |= subsets[j-A[i]]<<A[i] | subsets[j-A[i]];
    }
    cout<<"NO\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
