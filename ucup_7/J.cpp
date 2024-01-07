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
typedef int ll;
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
    ll n, q;
    cin>>n>>q;
    unordered_map<ll, ll> cnt;

    struct node {
        node *left, *right;
        ll id, tag;

        node(ll i, ll t): left(nullptr), right(nullptr), id(i), tag(t) {}
    };

    unordered_map<ll, node*> indices;

    function<void(ll, ll, node*, ll, ll, ll)> update = [&] (ll l, ll r, node *k, ll X, ll Y, ll tag) {
        if (X<=l && Y>=r && k->tag < 2) {
            cnt[k->id] -= k->tag;
            cnt[k->id] += tag;
            k->tag = tag;
            return;
        }

        if (k->tag < 2) {
            cnt[k->id] -= k->tag;
            k->left = new node(k->id<<1, k->tag);
            k->right = new node(k->id<<1|1, k->tag);
            cnt[k->left->id] += k->left->tag;
            cnt[k->right->id] += k->right->tag;
        }

        ll m = l + (r-l)/2;
        if (X<=m) update(l, m, k->left, X, Y, tag);
        if (Y>m)  update(m+1, r, k->right, X, Y, tag);

        if (k->left->tag<2 && k->right->tag<2 && k->left->tag == k->right->tag) {
            cnt[k->left->id] -= k->left->tag;
            cnt[k->right->id] -= k->right->tag;
            k->tag = k->left->tag;
            cnt[k->id] += k->tag;
            delete(k->left);
            delete(k->right);
            k->left = nullptr;
            k->right = nullptr;
        } else k->tag=2;
    };

    function<ll(ll, ll, ll, ll)> query = [&] (ll l, ll r, ll k, ll p) {
        if (l==r) return cnt[k];
        ll m = l + (r-l)/2;
        if (p<=m) return query(l, m, k<<1, p) + cnt[k];
        else      return query(m+1, r, k<<1|1, p) + cnt[k];
    };

    REP(i, q) {
        string s;
        cin>>s;
        if (s=="?") {
            ll x;
            cin>>x;
            cout<<query(1, n, 1, x)<<endl;
        } else {
            ll l, r, x;
            cin>>l>>r>>x;
            ll d = 1 - (s=="-");
            if (!indices.count(x)) indices[x] = new node(1, 0);
            update(1, n, indices[x], l, r, d);
        }
    }
}

int main() {
    int t=1;
    IO;
    // cin >> t;
    while (t--) solve();
}
