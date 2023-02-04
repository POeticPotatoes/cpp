#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
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
const ll N = 4e5 + 10;

ll cur, n, top[N]{}, pre[N]{}, req[N]{};
vector<int> adj[N]{}, ans;
MinHeap<pair<int, int>> q;

void solve() {
    cin>>n;
    REP(i,n) {
        cin>>top[i]>>pre[i];
        REP(j, pre[i]) {
            cin>>cur;
            adj[i].eb(--cur);
            req[cur]++;
        }
    }
    REP(i, n) {
        deb(i, req[i]);
    }
    REP(i, n) if (!req[i]) q.emplace(top[i], i);

    while (q.size()) {
        auto i = q.top(); q.pop();
        deb(i);
        ans.eb(i.second);
        for (auto j: adj[i.second]) {
            req[j]--;
            if (!req[j]) { 
                deb(j);
                q.push({top[j], j});
            }
        }
    }
    deb(ans);
    ll m = 0;
    REP(i, n)
        m = max(m, i+(top[ans[n-1-i]]));
    cout<<m<<endl;
}

int main() {
    IO;
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
