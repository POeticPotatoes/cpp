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

void solve() {
    ll n, cur;
    cin>>n;
    vll nums(n);
    vector<pair<ll, ll>> p;

    REP(i, n) cin>>nums[i];
    REP(i, n) {
        cin>>cur;
        p.eb(pair<ll,ll> {cur, nums[i]});
    }
    sort(all(p));

    cout<<p[0].second;
    FOR(i,1,n) cout<<" "<<p[i].second;
    cout<<endl;
}

int main() {
    //IO;
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
