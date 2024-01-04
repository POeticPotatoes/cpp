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
    ll d, n;
    cin>>d>>n;
    map<vll, ll> H;
    vll ans(d);
    REP(i, d) {
        vll dsu(n+1);
        iota(all(dsu), 0);
        vector<pair<ll, pair<ll, ll>>> A;
        vll hash;
        REP(j, n-1) {
            ll a, b, c;
            cin>>a>>b>>c;
            A.push_back({c, {a, b}});
        }
        sort(all(A), greater<pair<ll, pair<ll, ll>>>());

        function<ll(ll)> parent = [&](ll a) {
            if (dsu[a] != a) dsu[a] = parent(dsu[a]);
            return dsu[a];
        };
        
        set<ll> cur;
        REP(j, n-1) {
            if (!j || A[j].first != A[j-1].first) {
                for (auto a: cur) {
                    hash.eb(a);
                    hash.eb(parent(a));
                }
                cur.clear();
                hash.eb(-1);
                hash.eb(A[j].first);
            }
            ll a = parent(A[j].second.first),
               b = parent(A[j].second.second);
            if (a>b) swap(a, b);
            cur.insert(a);
            cur.insert(b);
            dsu[a] = b;
        }
        for (auto a: cur) {
            hash.eb(a);
            hash.eb(parent(a));
        }
        deb(hash);
        if (H.find(hash) != H.end()) ans[i] = H[hash];
        else {
            H[hash] = i+1;
            ans[i] = i+1;
        }
    }
    REP(i, d) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
