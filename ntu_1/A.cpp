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

ll n, m;

struct cmp {
    bool operator() (const pair<string, int> &a, const pair<string, int> &b) const {
        REP(i, m) {
            if (a.first[i] != b.first[i]) 
                return (i&1)?a.first[i]>b.first[i]:a.first[i]<b.first[i];
        }
        return 0;
    }
};

void solve() {
    cin>>n>>m;
    vector<pair<string, int>> A(n);
    REP(i, n) { cin>>A[i].first; A[i].second = i+1; }

    sort(all(A), cmp());
    REP(i, n) cout<<A[i].second<<" ";
    cout<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
