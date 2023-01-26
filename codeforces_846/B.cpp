#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll i = (a); (i) <= (b); (i)++);
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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N =3e5;

ll n, A[N], s, m;

bool check(set<ll> &sums, ll v) {
    ll a = v;
    while (a<s) {
        if (sums.count(a)) return true;
        a+=v;
    }
    return false;
}

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];
    set<ll> sums;
    s = 0;
    REP(i, n) {
        sums.insert(s);
        s+=A[i];
    }
    deb(s);
    for(int i=2;i<=s/2;i++) {
        if (!(s%i) && check(sums, s/i))
            return (void) (cout<<s/i<<endl);
    }
    cout<<1<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
