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
    ll n, k;
    cin>>n>>k;
    vll A(n), sum(4*n), fixed(4*n), fixedsum(4*n), tag(4*n);
    vector<pair<pair<ll, ll>, ll>> R;
    REP(i, n) cin>>A[i];
    REP(i, k) {
        ll a, b, c;
        cin>>a>>b>>c;
        R.eb({a, b}, c);
    }

    sort(all(R), [&] (pair<pair<ll, ll>, ll> &a, pair<pair<ll, ll>, ll> &b) {
            return a.first.second<b.first.second;
        });

    function<void(ll, ll, ll)> build(ll l, ll r, ll k) {
        if (l==r) {
            sum[k] = A[i]==0?-1:A[i];
            fixed[k] = A[i]!=0;
            fixedsum[k] = A[i];
            tag[k] = A[i];
        }

        ll m = l + (r-l)/2;
        build(l, m, k<<1);
        build(m+1, r, k<<1|1);
        sum[k] = sum[k<<1]+sum[k<<1|1];
        fixedsum[k] = sum[k];
        fixed[k] = fixed[k<<1]+fixed[k<<1|1];
    };
    build(0, n-1, 1);

    auto propagate = [&] (ll l, ll r, ll k) {
        ll m = l + (r-l)/2, lef = k<<1, rig = k<<1|1;
        ll c = min((r-m-fixed[rig]+fixedsum[rig]), sum[k] - sum[lef]);
        sum[rig] = max(sum[rig], c);
        tag[rig] = 1;
        sum[lef] = max(sum[k]-c+fixedsum[lef], sum[lef]);
        tag[lef] = 1;
        tag[k] = 0;
    };

    function<ll(ll, ll, ll, ll, ll)> query = [&] (ll l, ll r, ll k, ll X, ll Y) {
        if (X<=l && Y>=r) {
            return sum[k];
        }
        ll m = l+(r-l)/2;
        if (tag) propagate(l, r, k);
        ll ans = 0;
        if (X<=m) ans += query(l, m, k<<1, X, Y);
        if (Y>m)  ans += query(m+1, r, k<<1|1, X, Y);
        return ans;
    };

    function<ll(ll, ll, ll, ll, ll) update = [&] (ll l, ll r, ll k, ll X, ll Y, ll inc) {
        if (X<=l && Y>=r) {
            ll val = min((r-l+1-fixed[k]) - sum[k]-fixedsum[k], inc), diff = val-sum[k];
            sum[k] = val;
            return diff;
        }
    }
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
