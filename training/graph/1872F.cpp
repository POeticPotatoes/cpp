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
    ll n;
    cin>>n;
    vll A(n+1), C(n+1), cnt(n+1);
    FORN(i, 1, n) cin>>A[i];
    FORN(i, 1, n) cnt[A[i]]++;
    FORN(i, 1, n) cin>>C[i];

    queue<ll> Q;
    FORN(i, 1, n) if (!cnt[i]) Q.push(i);
    vll ans;
    while (Q.size()) {
        ll v = Q.front();Q.pop();
        ans.eb(v);
        cnt[A[v]]--;
        if (!cnt[A[v]]) Q.push(A[v]);
    }

    FORN(i, 1, n) {
        if (!cnt[i]) continue;
        vector<pair<ll, ll>> cyc;
        ll c = i;
        do {
            cyc.eb(C[c], c);
            cnt[c]=0;
            c = A[c];
        } while (c!=i);
        deb(cyc);
        ll sz = cyc.size();
        ll sm = 0;
        REP(j, sz) if (cyc[j].first < cyc[sm].first) sm=j;
        FORN(j, 1, sz) ans.eb(cyc[(j+sm)%sz].second);
    }
    REP(i, n) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main() {
    IO;
    int t=1;
    cin >> t;
    while (t--) solve();
}
