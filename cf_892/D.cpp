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

const ll N = 2e5;

ll n, q, ans[N];
vector<array<ll, 4>> A;
vector<pair<ll, ll>> Q;

struct compare{
    bool operator () (array<ll, 4> &a, array<ll, 4> &b) { return a[1] > b[1]; }
};

void solve() {
    cin>>n;
    A = vector<array<ll, 4>>(n);
    REP(i, n) REP(j, 4) cin>>A[i][j];
    cin>>q;
    Q = vector<pair<ll, ll>>(q);
    REP(i, q) {
        cin>>Q[i].first;
        Q[i].second = i;
    }
    sort(all(A), compare());
    sort(all(Q));
    multiset<ll> V;
    multiset<tuple<ll, ll, ll>, greater<tuple<ll, ll, ll>>> L;
    ll c = 0;

    // deb(A);
    // deb(Q);
    // 0 -> b, 1 -> l
    ROF(i, q-1, -1) {
        auto &[p, pos] = Q[i];
        while (c < n && A[c][1] >= p) {
            L.emplace(tuple<ll, ll, ll>{A[c][3], 0, c});
            L.emplace(tuple<ll, ll,ll>{A[c][0]-1, 1, c});
            c++;
        }
        // deb(L.size());
        // for (auto &[a, b, id]: L)
        //     printf("(%lld %lld %lld) ",a, b, id); 
        while (L.size() && get<0>(*L.begin()) >= p) {
            auto &[a, b, id] = *L.begin();
            if (b) V.erase(V.find(A[id][3]));
            else {
                A[id][3] = max(A[id][3], V.size()?*V.rbegin():0);
                V.emplace(A[id][3]);
            }
            L.erase(L.begin());
        }
        // deb(p, V);
        ans[pos] = max(p, V.size()?*V.rbegin():0);
    }
    REP(i, q) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
