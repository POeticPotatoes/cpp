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

ll n, H[N], A[N], m;
pair<ll, pair<ll, ll>> q[N];

void solve() {
    cin>>n;
    m = 0;
    REP(i, n) {
        ll k, c, prev=0;
        A[i] = 0;
        cin>>k;
        REP(j, k) {
            cin>>c;
            if (prev < c) {
                q[m++] = {c, make_pair(i, A[i]++)};
                prev = c;
            }
        }
        H[i] = A[i];
    }
    sort(q, q+m);
    ll h = 0, u = 0;
    REP(k, m) {
        auto &[v, p] = q[k];
        auto &[i, j] = p;
        if (k && v != q[k-1].first) h = u;
        H[i] = max(H[i], A[i]-j+h);
        if (j == A[i]-1) u = max(u, H[i]);
    }
    cout<<u<<"\n";
}

int main() {
    int t=1;
    IO;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}

