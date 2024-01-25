#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

void solve() {
    ll n;
    cin >> n;
    vll A(n+2);
    FORN(i, 1, n) cin>>A[i];
    vector<ll> pos, neg;
    ll grps = 0;

    REP(i, n+1) {
        if (A[i] - A[i+1] > 0){
            neg.push_back(A[i] - A[i+1]);
        }
        else if (A[i] - A[i+1] < 0) {
            pos.push_back(A[i+1] - A[i]);
        } else grps++;
    }
    sort(all(pos));
    sort(all(neg));
    deb("uwu");
    vector<pair<ll,ll>> reach_a, reach_b;
    for (ll i=1; i<(1 << (pos.size())); i++){
        ll sum = 0;
        for (ll j=0; j<pos.size(); j++){
            if (i & (1 << j) ) {
                sum += pos[j];
            }
        }
        reach_a.push_back({sum, i});
    }
    deb("iwi");
    for (ll i=1; i<(1 << (neg.size())); i++){
        ll sum = 0;
        for (ll j=0; j<neg.size(); j++){
            if (i & (1 << j) ) {
                sum += neg[j];
            }
        }
        reach_b.push_back({sum, i});
    }
    deb(pos, neg);
    deb("owo");
    sort(all(reach_a), 
        [&] (auto x, auto y){
            return x.first!=y.first?x.first<y.first:
                __builtin_popcountll(x.second) < __builtin_popcountll(y.second);
        }
    );
    sort(all(reach_b), 
            [&] (auto x, auto y){
            return x.first==y.first?(x.second)>(y.second):x.first<y.first;
            }
        );

    ll used_a = 0, used_b = 0;

    deb(reach_a, reach_b);
    for (ll i=0, j=0; i<reach_a.size() && j < reach_b.size();){
        while (i<reach_a.size() && reach_a[i].first < reach_b[j].first) i++;
        if (i==reach_a.size()) continue;
        while (j < reach_b.size() && reach_a[i].first > reach_b[j].first) j++;
        if (j==reach_b.size()) continue;
        if (reach_a[i].first != reach_b[j].first) continue;
        if (reach_a[i].second & used_a) {
            i++;
            continue;
        }
        if (reach_b[j].second & used_b) {
            j++;
            continue;
        }
        deb(reach_a[i], reach_b[j]);
        grps++;
        used_a = used_a | reach_a[i].second;
        used_b = used_b | reach_b[j].second;
        i++; j++;
    }
    cout << n+1-grps << endl;

}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
