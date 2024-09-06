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

vll mult{3,4,5,6};

ll modPow(ll v, ll p, ll m) {
    if (!p) return 1;
    ll ans = modPow(v, p/2, m);
    ans = (ans*ans) %m;
    if (p&1) ans = (ans*v) %m;
    return ans;
}

void solve() {

    ll n, q;
    cin>>n>>q;
    string s;
    cin>>s;

    vll uniq(n);
    vv<ll> hf(n, vll(4)), hb(n, vll(4));

    auto hash = [&] (string &A, vv<ll> &H) {
        REP(i, 4) H[0][i] = A[0];
        FOR(i, 1, n) REP(j, 4) H[i][j] = ((H[i-1][j]*mult[j])%MOD[j] + A[i]) %MOD[j];
    };

    hash(s, hf);
    string rev = s; reverse(all(rev));
    hash(rev, hb);

    auto f = [&] (ll l, ll r, vv<ll> &H) {
        vll res(4);
        REP(i, 4)
            res[i] = ((H[r][i]-(l?(H[l-1][i]*modPow(mult[i], r-l+1, MOD[i]))%MOD[i]:0))%MOD[i] + MOD[i])%MOD[i];
        return res;
    };

    auto palindrome = [&] (ll l, ll r) {
        vll h1 = f(l, r, hf);
        vll h2 = f(n-1-r, n-1-l, hb);
        return h1==h2;
    };

    uniq[0] = uniq[1] = 1;
    FOR(i, 2, n) uniq[i] = uniq[i-2] + (s[i] != s[i-2]);

    REP(i, q) {
        ll l, r;
        cin>>l>>r;
        l--, r--;

        ll k = r-l+1;
        ll o = k&1?r:r-1, e = k&1?r-1:r;
        ll ans = (k+1)*k/2 - 1;
        deb(s, l, r, e, o, uniq);
        if (uniq[l]==uniq[o] && uniq[l+1]==uniq[e]) {
            if (s[l]==s[l+1]) {
                cout<<"0\n";
                continue;
            }
            ll d = (k+1)/2;
            ans -= d*d - 1;
        } else if (palindrome(l, r)) ans-=k;
        cout<<ans<<"\n";
    }
}

int main() {
    REP(i, 4) mult[i] = rng() % MOD[i];

    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
