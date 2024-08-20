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
    vll A(n);
    REP(i, n) cin>>A[i];
    vll back(n), fow(n);

    FOR(i, 0, n-1) {
        if (!i || A[i]-A[i-1] > A[i+1]-A[i]) {
            fow[i+1] = fow[i]+1;
        } else fow[i+1] = fow[i] + A[i+1]-A[i];
    }

    ROF(i, n-1, 0) {
        if (i==n-1 || A[i+1]-A[i] > A[i]-A[i-1]) {
            back[i-1] = back[i] + 1;
        } else back[i-1] = back[i] + A[i]-A[i-1];
    }

    ll m;
    cin>>m;
    REP(i, m) {
        ll a, b;
        cin>>a>>b;
        a--, b--;

        if (a<b) {
            cout<<fow[b]-fow[a];
        } else cout<<back[b]-back[a];
        cout<<"\n";
    }
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
