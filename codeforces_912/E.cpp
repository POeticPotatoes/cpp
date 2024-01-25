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
    map<pair<ll, ll>, ll> P[2];
    vector<pair<ll, ll>> A(n+1);
    FORN(i, 0, n) {
        cin>>A[i].first>>A[i].second;
        if (i) P[(A[i].first ^ A[i].second) & 1][A[i]] = i;
    }

    bool p = (A[0].first ^ A[0].second) & 1;
    bool prefer = p^(P[p].size()>=(n+1)/2);

    auto opponent = [&] () {
        ll c;
        cin>>c;
        P[(A[c].first ^ A[c].second) & 1].erase(A[c]);
        n--;
    };
    deb(p, prefer);

    if (prefer == p) {
        cout<<"Second"<<endl;
        opponent();
    } else cout<<"First"<<endl;

    while(n--) {
        if (P[prefer].size()) {
            cout<<P[prefer].begin()->second<<endl;
            P[prefer].erase(P[prefer].begin());
        } else {
            cout<<P[prefer^1].begin()->second<<endl;
            P[prefer^1].erase(P[prefer^1].begin());
        }
        if (n) opponent();
    }
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
