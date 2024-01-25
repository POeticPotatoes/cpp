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
    int p;
    cin>>p;
    auto find = [&] (int v) {
        return (int) ((sqrt((ld) 1+8*p)+1)/2);
    };

    int n = find(p)-1;
    deb(n);

    vector<pair<int, int>> DP(p+1, {0, inf});

    DP[0] = {0, 0};

    FORN(i, 1, n) {
        int v = i*(i+1)/2;
        FORN(j, 1, p) {
            if (j>=v) {
                if (DP[j-v].second + i+1 <= DP[j].second) {
                    DP[j] = {i+1, DP[j-v].second+i+1};
                }
            }
        }
    }


    int c=p, ans=0, t=DP[p].second;
    while (c) {
        int u = DP[c].first;
        ans += u*(t-u);
        int v = u*(u-1)/2;
        c -= v;
    }
    ans>>=1;
    cout<<t<<" "<<ans<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
