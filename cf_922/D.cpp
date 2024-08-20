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
    vll A(n+2);
    FORN(i, 1, n) cin>>A[i];
    ll sum=0;
    FORN(i, 1, n) sum+=A[i];

    vector<ll> DP(n+2);
    multiset<ll> window;
    auto check = [&] (ll v) {
        memset(&DP[0], 0, sizeof(ll)*(n+2));
        window.clear();
        window.insert(0);
        ll l = 0, s = 0;
        FORN(i, 1, n+1) {
            while (s > v) {
                window.erase(window.find(DP[l]));
                s -= A[++l];
            }
            DP[i] = *window.begin() + A[i];
            // deb(i, l, window, DP[i]);
            window.insert(DP[i]);
            s += A[i];
        }
        return DP[n+1];
    };
    
    ll l =0, r=sum;
    while (l<r) {
        ll m = (l+r)/2;
        ll res = check(m);
        deb(m, res);
        if (res==m) return (void) (cout<<m<<"\n");
        if (res < m) r=m;
        else l = m+1;
    }
    
    ll ans = max(l, check(l));
    cout<<ans<<"\n";
}

int main() {
    IO;
    int t=1;
    cin >> t;
    while (t--) solve();
}
