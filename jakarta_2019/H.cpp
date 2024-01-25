#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;
#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
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
    ll n;
    cin>>n;
    vector<pair<pair<ll, ll>, ll>> A;
    float ans = 0;
    REP(i, n) {
        ll a, b;
        cin>>a>>b;
        ans = max(ans, a*b/2.0f);
        A.emplace_back(make_pair(a, b), i);
        A.emplace_back(make_pair(b, a), i);
    }

    sort(all(A));
    MaxHeap<pair<pair<ll, ll>, ll>> q;
    REP(i, n<<1) q.emplace(A[i]);

    REP(i, (n<<1)) {
        bool flag = false;
        while (q.size() && (q.top().second == A[i].second || q.top().first.second < A[i].first.first)) {
            flag |= q.top().second==A[i].second;
            q.pop();
        }
        if (q.size()) {
            auto p = q.top();
            deb(A[i], p, ans);
            ll h = A[i].first.first, v = min(A[i].first.second, p.first.first);
            ans = max(ans, (float) (h*v));
        }
        if (flag) {
            q.emplace(A[i]);
            q.emplace(make_pair(A[i].first.second, A[i].first.first), A[i].second);
        }

    }

    printf("%.1f\n", ans);
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
