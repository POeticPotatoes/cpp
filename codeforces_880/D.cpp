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

const ll N = 2e6;

ll n, m, k, A[N], l=0, r=0, res=0, ans=0, c=0;

void check(ll v) {
    if (v<0 || v>m) return;
    for (;l<n && A[l]<v;l++);
    for (;r<n && A[r]<=v;r++);

    if (r-l >= k) return;
    ll lpos = r-k<0? 0: v - (v - A[r-k] - 1)/2;
    ll rpos = l+k-1>=n? m: v + (A[l+k-1] - v - 1)/2; 
    deb(v, l, r, lpos, rpos, rpos-lpos+1);

    if (res < rpos - lpos +1) ans=v, res  = rpos-lpos+1;
}

void solve() {
    cin>>n>>m>>k;
    REP(i, n) cin>>A[i];

    sort(A, A+n);
    check(0);

    REP(i, n) {
        FORN(j, A[i]-5, A[i]+5)
            if (j>c) check(j);
        c = A[i]+5;
    }
    cout<<res<<" "<<ans<<"\n";
}

int main() {
    int t=1;
    IO;
    while (t--) solve();
}
