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
    ll n, k, m;
    cin>>n>>k>>m;
    string s;
    cin>>s;

    vv<ll> O(m, vll(k, INF));
    ROF(i, m-1, -1) {
        if (i<m-1) REP(j, k) O[i][j] = O[i+1][j];
        O[i][s[i]-'a']=i;
    }
    deb(O);

    string counter;
    ll p = 0;
    while (counter.size()<n) {
        ll ch=0, r=-1;
        REP(i, k) if (r<O[p][i]) {
            ch = i;
            r = O[p][i];
        }
        counter += (char) ('a'+ch);
        p = r;
        if (p>=m) break;
    }
    deb(counter, p);
    if (p>=m || counter.size()<n) {
        cout<<"NO\n"<<counter;
        FOR(i, counter.size(), n) cout<<"a";
        cout<<"\n";
        return;
    }
    cout<<"YES\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
