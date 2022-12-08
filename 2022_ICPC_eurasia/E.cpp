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

ll n, x=0, cur, splits, combines;
vector<int> nums;
vv<int> towers;

void solve() {
    cin>>n;
    towers = vv<int>(n);
    REP(i, n) {
        cin>>cur;
        towers[i] = vector<int>(cur);
        REP(j, cur) {
            cin>>towers[i][j];
            nums.eb(towers[i][j]);
        }
        x+=cur;
    }

    splits = x-n;
    combines = x-1;
    sort(all(nums));

    for (auto t: towers) {
        int size = t.size();
        REP(i, size) {
            int p = upper_bound(all(nums), t[i]) - nums.begin()-1;
            while (++p != nums.size() && i<size-1 && nums[p]==t[i+1]) {
                i++, splits--, combines--;
            }
        }
    }
    cout<<splits<<" "<<combines<<endl;
}

int main() {
    IO;
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
