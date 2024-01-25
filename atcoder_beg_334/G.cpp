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

const ll MOD[] = {999727999, 1070777777, 1000000007, 998244353};
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
const int M = MOD[3];
const int inf = (int)1e9;
const ll INF = 1e18;

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

void solve() {
    ll h, w;
    cin>>h>>w;
    vector<string> A(h);
    REP(i, h) cin>>A[i];

    const ll moves[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    vv<ll> ord(h, vll(w)), low(h, vll(w));

    auto valid = [&] (ll y, ll x) {
        return y>=0 && y<h && x>=0 && x<w && A[y][x] == '#';
    };

    function<ll(ll, ll, ll, ll, ll)> dfs = [&] (ll a, ll b, ll c, ll d, ll o) {
        low[a][b] = ord[a][b] = o;
        ll k = o;
        REP(i, 4) {
            ll y = a+moves[i][0], x = b+moves[i][1];
            if (!valid(y, x) || (y==c && x==d)) continue;
            if (!ord[y][x]) 
                k = min(k, dfs(y, x, a, b, o+1));
                // dfs(y, x, a, b, o+1));
            else k = min(k, low[y][x]);
        }
        return low[a][b]=k;
    };

    ll t=0, g=0, s=0;
    REP(a, h) REP(b, w) {
        if (A[a][b] == '.') continue;
        ll c=0;
        g++;
        if (!ord[a][b]) {
            t++;
            c--;
            dfs(a, b, -1, -1, 1);
        }
        REP(i, 4) {
            ll y = a+moves[i][0], x = b+moves[i][1];
            if (!valid(y, x)) continue;
            if (ord[a][b] == ord[y][x]-1 && low[y][x] >= ord[a][b])  {
                c++;
                //deb("!", a, b, y, x);
            }
        }
        s = (s + c + M) %M;
        //deb(a, b, c);
    }
    // deb(s);
    // REP(i, h) { deb(ord[i]); }
    // REP(i, h) { deb(low[i]); }
    s = (((t*g)%M) + s)%M;
    s = (s*modPow(g, M-2)) %M;

    cout<<s<<"\n";
}

int main() {
    int t=1;
    //cin >> t;
    while (t--) solve();
}
