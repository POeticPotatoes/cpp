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
    ll a, b, r;
    cin>>a>>b>>r;
    if (a>b) swap(a, b);
    auto f = [&] (ll m) {
        ll ans=b-a;
        ll cur=0;
        ROF(i, m, -1) {
            if ((cur | (1LL<<i))>r) continue;
            ll v = 1LL<<i;
            ll p = abs((a^v^cur) - (b^v^cur));
            if (p >= ans) continue;
            ans = p;
            cur |= 1LL<<i;
        }
        return ans;
    };
    ll ans = INF;
    ROF(i, 62, -1) ans = min(ans, f(i));
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
