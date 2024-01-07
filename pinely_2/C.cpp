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

void solve() {
    ll n, k;
    cin>>n>>k;
    vll A(n+1), vis(n+1);
    REP(i, n) cin>>A[i];
    set<ll> unvis;
    REP(i, n) vis[A[i]]++;
    FORN(i, 0, n) if (!vis[i]) unvis.insert(i);
    REP(i, n) {
        ll m = *unvis.begin();
        unvis.erase(m);
        if (!--vis[A[i]]) unvis.insert(A[i]);
        A[i] = m;
    }
    A[n] = *unvis.begin();
    ll o = ((1-k) % (n+1) + n+1) % (n+1);
    REP(i, n) cout<<A[(o+i) % (n+1)]<<" ";
    cout<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
