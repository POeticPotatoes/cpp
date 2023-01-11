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

ll n, x, sum=0;
int status[200000]{};
pair<ll, ll> ex[200000];
MinHeap<pair<ll, ll>> a,b,c;
MaxHeap<pair<ll, ll>> d;

ll replace() {
    while ((c.size() && d.size()) && status[d.top().second] == 2) d.pop();
    if (c.empty() || d.empty()) return INF;
    //cout<<c.top().first<<", "<<d.top().first<<endl;
    return c.top().first-d.top().first;
}

ll upgrade() {
    while (b.size() && status[b.top().second] != 1) b.pop();
    if (b.empty()) return INF;
    return b.top().first;
}

void solve() {
    cin>>n>>x;

    REP(i, n) {
        cin>>ex[i].first;
        a.push({ex[i].first, i});
    }
    while (a.size() && sum+a.top().first <= x) {
        sum += a.top().first;
        status[a.top().second] = 1;
        a.pop();
    }
    REP(i, n) {
        cin>>ex[i].second;
        if (status[i]) {
            b.push({ex[i].second-ex[i].first, i});
            d.push({ex[i].first, i});
        } else c.push({ex[i].second, i});
    }

    // REP(i, n) cout<<status[i];
    // cout<<endl;
    while (true) {
        ll r = replace(), u = upgrade();
        if (r<u) {
            if (r+sum>x) break;
            // cout<<r<<"replaced "<<d.top().second<<" with "<<c.top().second<<endl;
            sum += r;
            status[d.top().second] = 0;
            status[c.top().second] = 2;
            d.pop(); c.pop();
            continue;
        }
        // cout<<u<<"upgraded "<<b.top().second<<endl;
        if (u+sum>x) break;
        sum+=u;
        status[b.top().second] = 2;
        b.pop();
    }

    REP(i, n) cout<<status[i];
    cout<<endl;
}

int main() {
    IO;
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
