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
    vector<pair<ll, ll>> A(n), B(n), C(n);
    REP(i, n) {
        cin>>A[i].first;
        A[i].second = i;
    }
    REP(i, n) {
        cin>>B[i].first;
        B[i].second = i;
    }
    REP(i, n) {
        cin>>C[i].first;
        C[i].second = i;
    }

    sort(all(A), greater<pair<ll, ll>>());
    sort(all(B), greater<pair<ll, ll>>());
    sort(all(C), greater<pair<ll, ll>>());

    ll ans= 0;
    REP(i, 3) REP(j, 3) REP(k, 3) {
        if (A[i].second == B[j].second
                || A[i].second == C[k].second
                || B[j].second == C[k].second) continue;
        ans = max(ans, A[i].first + B[j].first + C[k].first);
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
