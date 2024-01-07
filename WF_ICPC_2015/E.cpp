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

ll y, l;

ll convert(ll n, ll b) {
    ll k=0, p=1;
    for (;n;k+= (n%b)*p, n/=b, p*=10)
        if ((n%b)>9) return -1;
    return k;
}

ll unconvert(ll n, ll b) {
    ll v = 0, p=1;
    while (n) {
        v += p*(n%10);
        n /= 10;
        if (1e18/b < p) return -1;
        p*=b;
    }
    return v;
}

void solve() {
    cin>>y>>l;
    ll ans = 0;
    // check l
    FORN(i, l, 1e5) {
        ll lef=10, rig=1e18;
        bool flag = 0;
        while (lef<rig) {
            ll m = (lef+rig)>>1,
               res = unconvert(i, m);
            if (res == -1 || res>y) rig=m;
            else lef = m+1;
            if (res == y) {
                flag = 1;
                ans = m;
                break;
            }
        }
        if (flag) break;
    }
    deb(ans);

    // check b
    ROF(i, 1e5, 9) {
        ll res = convert(y, i);
        if (res<l) continue;
        deb(res, i);
        ans = max(ans, i);
        break;
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    deb(convert(23125, 10));
    // cin >> t;
    while (t--) solve();
}
