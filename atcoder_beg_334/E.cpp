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

    const ll dir[4][2]{0,1,1,0,-1,0,0,-1};
    
    vv<ll> vis(h, vll(w));

    auto valid = [&] (ll x, ll y) {
        return !(x<0 || x==h || y<0 || y==w);
    };

    function<void(ll, ll, ll)> dfs = [&] (ll x, ll y, ll v) {
        if (A[x][y] =='.') return;
        if (vis[x][y]) return;
        vis[x][y] = v;
        REP(i, 4) {
            if (valid(x + dir[i][0], y + dir[i][1]))
                dfs(x + dir[i][0], y + dir[i][1], v);
        }
    };

    ll comps=0;
    REP(i, h) REP(j, w) {
        if (A[i][j] == '#' && !vis[i][j]) 
            dfs(i, j, ++comps);
    }

    ll t=0, cnt=0;
    REP(i, h) REP(j, w) {
        if (A[i][j]=='#') continue;
        cnt++;
        set<ll> neighbours;
        REP(k, 4) {
            ll x = i+dir[k][0], y = j + dir[k][1];
            if (valid(x, y) && vis[x][y])
                neighbours.insert(vis[x][y]);
        }
        ll a;
        if (neighbours.size())
            a = comps - max(0LL, (ll) (neighbours.size()-1));
        else a = comps+1;
        deb(i, j, a);
        t = (t+a) %M;
    }
    
    t = (t*modPow(cnt, M-2))%M;
    cout<<t<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
