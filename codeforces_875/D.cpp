#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (int i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (int i = (a); (i) <= (b); (i)++)
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

const ll N = 2e5+5;

int n, lim, V[640][N];
pair<int, int> A[N];

int get(int a, int b) { 
    return a<=lim&&b>=1&&b<=n?V[a][b]:0; 
}

void solve() {
    cin>>n;
    lim = ceil(sqrt(n<<1));
    REP(i, n) cin>>A[i].first;
    REP(i, n) cin>>A[i].second;

    REP(i, n) if (A[i].first<=lim) V[A[i].first][A[i].second]++;
    ll ans=0, s=0;

    REP(i, n) s += get(A[i].first, A[i].first*A[i].first-A[i].second); 
    for (int i=2; i<=lim; i+=2) s -= get(i, (i*i)>>1);
    ans += s>>1;

    REP(i, n) {
        ll m = min(A[i].first-1, lim);
        FORN(j, 1, m) ans += get(j, A[i].first*j-A[i].second);
    }

    FORN(i, 1, lim) FORN(j, 1, n) V[i][j] = 0;
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
