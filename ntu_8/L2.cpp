#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

void solve() {
    int n; cin >> n;
    pair<ll, ll> a[n];
    multiset<pair<ll,ll>, greater<pair<ll,ll>>> st1;
    multiset<pair<ll,ll>, greater<pair<ll,ll>>> st2;
    ll sum = 0;

    REP(i, n) {
        int x, y; cin >> x >> y;
        a[i] = {x,y};
        st1.insert({x,i});
        st2.insert({y,i});
        sum += x;
    }

    sum += st2.begin()->first;
    vll ans;
    ans.push_back(sum);
    int k = n;

    while(--k){
        auto minA = st1.begin(), min2A = next(minA);
        auto minB = st2.begin(), min2B = next(minB);
        ll costX = minA->first;
        ll costY = a[minB->second].first + (minB->first - min2B->first);
        if (costX > costY){
            sum -= costX;
            st2.erase({a[minA->second].second, minA->second});
            st1.erase(minA);
        }
        else {
            sum -= costY;
            st1.erase({a[minB->second].second, minB->second});
            st2.erase(minB);

        }
        ans.push_back(sum);
        deb(costX, costY);
    }
    reverse(ans.begin(), ans.end());
    REP(i, n) cout << ans[i] << '\n';



}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}

