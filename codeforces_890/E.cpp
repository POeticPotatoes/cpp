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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 2e6;

ll n, A[N], S[N], ans=0;
vv<ll> sz;

template<ll S>
void split(vll &s, ll sum) {
    sum--;
    deb(s, sum);
    bitset<S> DP;
    map<ll, ll> K;
    for (auto i: s) K[i]++;
    for (auto &[v, c]: K) while (c>2) K[v<<1]++, c-=2;

    DP[0] = 1;
    for (auto &[v, c]: K) DP |= DP<<v;
    ll p = DP._Find_next((sum>>1)-1);
    deb(p);
    ans += p*(sum-p);
}

void solve() {
    cin>>n;
    sz = vv<ll>(n+1);
    FORN(i, 2, n) cin>>A[i];
    ROF(i, n, 0) {
        S[i]++;
        sort(all(sz[i]));
        S[A[i]] += S[i];
        sz[A[i]].eb(S[i]);
    }
    FORN(i, 1, n) {
        if (S[i]<10) split<20>(sz[i], S[i]);
        else if (S[i]<100) split<200>(sz[i], S[i]);
        else if (S[i]<1000) split<2000>(sz[i], S[i]);
        else if (S[i]<10000) split<20000>(sz[i], S[i]);
        else if (S[i]<100000) split<200000>(sz[i], S[i]);
        else split<2000000>(sz[i], S[i]);
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
