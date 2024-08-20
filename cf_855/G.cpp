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

vv<ll> adj;
vll A, B;
map<vll, int> mp;
ll n, id=1;

bool dfs(ll v, ll p) {
    vll h;
    for (auto c: adj[v]) if (c != p) {
        dfs(c, v);
        h.eb(A[c]);
    }
    sort(all(h));
    if (mp[h]) {
        A[v] = mp[h];
        return B[A[v]];
    }
    int s=0, x = id++;
    A[v] = x;
    mp[h] =  x;
    REP(i, h.size()) {
        if (i<h.size()-1 && h[i] == h[i+1]) {
            i++;
            continue;
        }
        if (s++ || !B[h[i]])
            return (B[x] = 0);
    }
    return (B[x] = 1);
}

void solve() {
    cin>>n;
    adj = vv<ll>(n+1);
    A = B = vll(n+1);
    mp.clear();
    ll a, b;
    id = 1;
    REP(i, n-1) {
        cin>>a>>b;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    cout<<(dfs(1, 0)?"YES\n":"NO\n");
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
