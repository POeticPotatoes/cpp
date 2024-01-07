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
    ll n, k, c, q;
    string s;
    cin>>n>>k;
    cin>>s;

    vll L(k+1);
    REP(i, k) {
        cin>>L[i];
        L[i]--;
    }
    L[k]=n;
    REP(i, k) cin>>c;
    cin>>q;
    vll A(q);
    REP(i, q) cin>>A[i];

    vector<string> seg;
    REP(i, k) seg.eb(s.substr(L[i], L[i+1]-L[i]));
    sort(all(A));

    ll p=0, cur=0;
    REP(i, k) {
        ll m = seg[i].size();
        cur += m;
        ll mid = (m+1)/2;
        vll swap(mid);
        while (p<q && A[p]<=cur) {
            ll t = A[p++];
            ll pos = min(cur-t, m-1-cur+t);
            swap[pos]^=1;
        }
        bool flipped=false;
        REP(j, mid) {
            flipped^=swap[j];
            if (flipped) cout<<seg[i][m-j-1];
            else cout<<seg[i][j];
        }
        if (m&1) flipped^=swap[m>>1];
        ROF(j, m/2-1, -1) {
            if (flipped) cout<<seg[i][j];
            else cout<<seg[i][m-j-1];
            flipped^=swap[j];
        }
    }
    cout<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
