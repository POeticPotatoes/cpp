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
    ll n, q;
    cin>>n>>q;
    map<ll, ll> orig;

    auto factorize = [&] (map<ll, ll> &m, ll v) {
        ll t=v;
        for (int i=2;i*i<=v;i++) {
            while (!(t%i)) {
                m[i]++;
                t/=i;
            }
        }
        if (t>1) m[t]++;
    };

    factorize(orig, n);

    ll div=1;
    for (auto &[a, b]: orig) div*=b+1;

    map<ll, ll> cur=orig;
    ll curdiv=div;
    REP(j, q) {
        ll x, v;
        cin>>x;
        if (x==2) {
            cur=orig;
            curdiv=div;
            continue;
        }
        cin>>v;

        map<ll, ll> added;
        factorize(added, v);

        for (auto &[a, b]: added) {
            curdiv /= cur[a]+1;
            curdiv *= 1+(cur[a]+=b);
        }
        
        map<ll, ll> comp;
        factorize(comp, curdiv);

        bool flag=true;
        for (auto &[a, b]: comp) {
            if (cur[a] < b) {
                flag=false;
                break;
            }
        }
        cout<<(flag?"YES\n":"NO\n");
    }
    cout<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
