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
    ll m;
    cin>>m;
    vll cnt(30);

    auto query = [&] (ll c) {
        vll cur = cnt;
        ROF(i, 30, -1) {
            if (!((c>>i)&1)) continue;
            ll v = 1<<i;
            deb(v);
            ROF(j, i, -1) {
                ll amt = min(cur[j], v/(1<<j));
                v -= (1<<j)*amt;
                cur[j] -= amt;
                if (!v) break;
                deb(amt, v, j, cur);
            }
            if (v>0) return (void) (cout<<"NO"<<endl);
        }
        cout<<"YES"<<endl;
    };

    REP(t, m) {
        ll q, c; cin>>q>>c;
        if (q==1) {
            cnt[c]++;
        } else {
            query(c);
        }
    }
}

int main() {
    int t=1;
    IO;
    // cin >> t;
    while (t--) solve();
}
