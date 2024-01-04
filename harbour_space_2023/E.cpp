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

const ll N = 3e5;

ll n, A[N];

struct node {
    ll size=0;
    node *next[2]{};

    ll getSize(ll a) { return next[a]?next[a]->size:0; }

    void build(ll a, ll pos) {
        size++;
        if (pos--) {
            int b = a>>pos&1;
            if (!next[b]) next[b] = new node();
            next[b]->build(a, pos);
        }
    }
};

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans) %M;
    if (p&1) ans = (ans*v) %M;
    return ans;
}

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];

    node T;
    REP(i, n) T.build(A[i], 30);

    ll ans = 0;
    REP(i, n) {
        ll count = 0;
        node c = T;
        ROF(j, 29, -1) {
            int b = A[i]>>j&1;
            ans = (ans + c.getSize(b^1) * (count + 1 + b)) %M;
            c = *(c.next[b]);
            count += b;
        }
        ans = (ans + (c.size) * (count+1)) %M;
    }
    cout<<((ans * modPow((n*n)%M, M-2)) %M)<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
