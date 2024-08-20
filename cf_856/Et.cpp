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
const int M = MOD[2];
const int inf = (int)1e9;
const ll INF = 1e18;

const ll N = 3e5;

ll n, A[N];
vv<ll> adj, H;
vll INC(3);

vll operator +(const vll a, const vll b) {
    vll c(3);
    REP(i, 3) c[i] = (a[i] + b[i]) % MOD[i];
    return c;
}

vll operator +(const vll a, const ll b) {
    vll c(3);
    REP(i, 3) c[i] = (a[i] + b) % MOD[i];
    return c;
}

vll operator -(const vll a, const vll b) {
    vll c(3);
    REP(i, 3) c[i] = (a[i] - b[i] + MOD[i]) % MOD[i];
    return c;
}

vll operator *(const vll a, const vll b) {
    vll c(3);
    REP(i, 3) c[i] = (a[i] * b[i]) % MOD[i];
    return c;
}

void updateChildren(ll v, ll p) {
    H[v] = {0,0,0};
    for (auto c: adj[v]) if (c != p) {
        updateChildren(c, v);
        H[v] = H[v] + H[c];
    }
    H[v] = (H[v]*INC) + 1;
}

void updateParents(ll v, ll p) {
    if (v>1) H[v] = H[v] + INC * (H[p] - INC * H[v]);
    for (auto c:adj[v]) if (c != p) updateParents(c, v);
}

void solve() {
    cin>>n;
    H = adj = vv<ll>(n+1);
    ll a, b;
    REP(i, n-1) cin>>A[i];
    REP(i, n-1) {
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    vll F(n), I(3), B={1,1,1};
    REP(i, n-1) F[A[i]]++;
    ROF(i, n-1, -1) I = I*INC + F[i];
    
    updateChildren(1, 0);
    updateParents(1, 0);
    
    vv<ll> H3(n);
    REP(i, n) {
        H3[i] = I+B;
        B = B*INC;
    }
    vll ans;
    vector<pair<vll, ll>> H1;
    FORN(i, 1, n) H1.eb(H[i], i);
    sort(all(H1));
    sort(all(H3));
    int pos = 0;
    for (auto &v: H3) {
        while (pos<n && H1[pos].first < v) pos++;
        while (pos<n && H1[pos].first == v) {
            ans.eb(H1[pos].second);
            pos++;
        }
    }
    sort(all(ans));
    cout<<ans.size()<<endl;
    for (auto c: ans) cout<<c<<" ";
    cout<<endl;
}

int main() {
    REP(i, 3) INC[i] = rng() % MOD[i];
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
