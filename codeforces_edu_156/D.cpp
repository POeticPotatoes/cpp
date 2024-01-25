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
const int M = MOD[3];
const int inf = (int)1e9;
const ll INF = 1e18;

void solve() {
    ll n, m;
    cin>>n>>m;
    n--;
    string s;
    cin>>s;

    vll st(4*n);
    function<void(ll, ll, ll)> build =[&] (ll l, ll r, ll k) {
        if (l==r) {
            st[k] = s[l]=='?'?l:1;
            return;
        }
        ll mid = (l+r)>>1;
        build(l, mid, k<<1);
        build(mid+1, r, k<<1|1);
        st[k] = (st[k<<1]*st[k<<1|1]) %M;
    };

    function<ll(ll, ll, ll, ll)> update = [&] (ll l, ll r, ll k, ll v) {
        if (l==r) return (st[k] = s[l]=='?'?l:1);
        ll mid = (l+r) >> 1;
        if (v>mid) return st[k] = (st[k<<1] * update(mid+1, r, k<<1|1, v)) %M;
        else return st[k] = (st[k<<1|1] * update(l, mid, k<<1, v)) %M;
    };

    build(0, n-1, 1);
    cout<<st[1]<<"\n";
    REP(i, m) {
        ll a;
        char b;
        cin>>a>>b;
        s[--a] = b;
        cout<<update(0, n-1, 1, a)<<"\n";
    }
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
