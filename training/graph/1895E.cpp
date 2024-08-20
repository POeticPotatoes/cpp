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
#define rall(x) (x).rbegin(), (x).rend()
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
    ll n, m;
    cin>>n;
    vll A(n), B(n), tA(n, -1);
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>B[i];
    cin>>m;
    vll C(m), D(m), tB(m, -1);
    REP(i, m) cin>>C[i];
    REP(i, m) cin>>D[i];

    vector<pair<ll, ll>> dA, dB;
    REP(i, n) dA.eb(B[i], i);
    REP(i, m) dB.eb(D[i], i);

    sort(rall(dA)); sort(rall(dB));
    ll p=0;
    ROF(i, n-1, -1) {
        auto &[d, a] = dA[i];
        while (p<m && C[dB[p].second] <= d) p++;
        if (p==m) break;
        tA[a] = dB[p].second;
    }
    p=0;
    ROF(i, m-1, -1) {
        auto &[d, b] = dB[i];
        while (p<n && A[dA[p].second] <= d) p++;
        if (p==n) break;
        tB[b] = dA[p].second;
    }

    vll visA(n), visB(m);
    REP(i, n) if (tA[i] == -1) visA[i] = 1;
    REP(i, m) if (tB[i] == -1) visB[i] = 2;

    function<ll(ll, ll)> check = [&] (ll v, ll k) {
        if (k==1) {
            if (visA[v]) return visA[v];
            visA[v] = 3;
            return visA[v] = check(tA[v], 0);
        } else {
            if (visB[v]) return visB[v];
            visB[v] = 3;
            return visB[v] = check(tB[v], 1);
        }
    };

    ll w=0, l=0, d=0;
    REP(i, n) {
        if (!visA[i]) check(i, 1);
        if (visA[i]==1) w++;
        if (visA[i]==2) l++;
        if (visA[i]==3) d++;
    }

    cout<<w<<" "<<d<<" "<<l<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
