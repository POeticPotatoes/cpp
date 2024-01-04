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

struct node { ll val; node * left; node * right;};

ll n, k, inp[51][21], vis[51];
node *trees[51];

void insert(node *nd, ll v) {
    if (nd->val< v) {
        if (nd->left) insert(nd->left, v);
        else nd->left = new node{v, NULL, NULL};
        return;
    }

    if (nd->right) insert(nd->right, v);
    else nd->right = new node{v, NULL, NULL};
}

bool compare(node *a, node *b) {
    if (a == NULL || b == NULL) return a==b;
    deb(a->val, b->val);
    return compare(a->left, b->left) && compare(a->right, b->right);
}

void solve() {
    cin>>n>>k;
    REP(i, n) REP(j, k) cin>>inp[i][j];
    REP(i, n) {
        trees[i] = new node{inp[i][0], NULL, NULL};
        FOR(j, 1, k) insert(trees[i], inp[i][j]);
    }
    ll ans = 0;
    REP(i, n) {
        if (vis[i]) continue;
        ans++;
        FOR(j, i+1, n) vis[j] |= compare(trees[i], trees[j]);
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
