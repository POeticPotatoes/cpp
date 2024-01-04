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

const ll N = 301;

ll n, lim, s=0, j, v, A[N], V[N], DP[N][N*N];

void first() {
    cout<<"First\n";
    ll p=1;
    while (1) {
        cout<<p<<endl;
        cin>>j;
        if (j<=0) return;
        v = min(A[p], A[j]);
        A[p] -= v;
        A[j] -= v;
        while (!A[p]) p++;
    }
}

void second() {
    cout<<"Second\n";
    ll p=lim;
    ROF(i, n, 0) {
        V[i] = DP[i][p]-1;
        p = p - (DP[i][p]-1)*A[i];
    }
    ll c[2]{1, 1};
    while (!V[c[1]]) c[1]++;
    while (V[c[0]]) c[0]++;
    while (1) {
        cin>>j;
        if (j<=0) return;
        ll t = V[j];
        ll &o = c[t^1];
        while (V[o] == t || !A[o]) o++;
        cout<<o<<endl;
        v = min(A[j], A[o]);
        A[o] -= v, A[j] -= v;
    }
}

void solve() {
    cin>>n;
    FORN(i, 1, n) {
        cin>>A[i];
        s+=A[i];
    }
    if (s&1) return first();
    lim = s>>1;
    DP[0][0] = 1;
    FORN(i, 1, n) {
        FORN(k, 0, lim) {
            if (k-A[i]>=0 && DP[i-1][k-A[i]]) DP[i][k] = 2;
            if (DP[i-1][k]) DP[i][k] = 1;
        }
    }
    if (!DP[n][lim]) return first();
    second();
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
