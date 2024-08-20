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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll n, m, m1, m2, ans, c;

void solve() {
    cin>>n>>m1>>m2;
    vll A{1};
    vector<pair<ll, ll>> V;
    map<ll, ll> d;
    for (int i=2;i*i<=m1;i++)
        while (!(m1%i))
            m1/=i, d[i]++;
    if (m1>1)  d[m1]++;
    for (int i=2;i*i<=m2;i++)
        while (!(m2%i))
            m2/=i, d[i]++;
    if (m2>1)  d[m2]++;

    for (auto &p: d) V.eb(p);
    ll v = V.size(), s, x;
    REP(i, v) {
        s = A.size();
        REP(j, s) {
            x = A[j];
            REP(k, V[i].second)
                A.eb(x *= V[i].first);
        }
    }
    sort(all(A));
    deb(A);
    ans=0, c=0;
    for (auto i: A) {
        deb(i);
        if (i<=n) {
            ans++;
            c ^= 1;
            deb(i, c);
            continue;
        }
        auto p = lower_bound(all(A), (i+n-1)/n);
        for (;(p!=A.end()) && (*p<=n);p++) {
            if (!(i%*p)) {
                ans++;
                c ^= *p;
                deb(*p, c);
                break;
            }
        }
    }
    cout<<ans<<" "<<c<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
