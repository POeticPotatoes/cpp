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

ll n, q, c, A[300000], x, y;

void solve() {
    cin>>n;
    map<ll, ll> v;
    multiset<ll> d;
    FORN(i, 1, n) {
        cin>>A[i];
        v[A[i]]++;
    }
    for (auto p = v.begin();next(p)!=v.end();p++)
        d.insert(next(p)->first - p->first);

    cin>>q;
    REP(i, q) {
        cin>>x>>y;
        auto p = v.find(A[x]);
        p->second--;
        if (!p->second) {
            if (p != v.begin()) d.erase(d.find(p->first - prev(p)->first));
            if (next(p) != v.end()) d.erase(d.find(next(p)->first - p->first));
            if (p != v.begin() && next(p) != v.end()) d.insert(next(p)->first - prev(p)->first);
            v.erase(p);
        }

        A[x] = y;
        if (v.find(y) != v.end()) v[y]++;
        else {
            v[y]++;
            auto p = v.find(A[x]);
            if (p != v.begin()) d.insert(p->first - prev(p)->first);
            if (next(p) != v.end()) d.insert(next(p)->first - p->first);
            if (p != v.begin() && next(p) != v.end()) d.erase(d.find(next(p)->first - prev(p)->first));
        }
        cout<<(d.size()?*d.rbegin(): 0) + v.rbegin()->first<<" ";
    }
    cout<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
