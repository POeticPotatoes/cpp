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
    vector<pair<ll, ll>> A(n);
    REP(i, n) cin>>A[i].first>>A[i].second;

    set<ll> U;
    REP(i, n) FOR(j, i+1, n) {
        if (A[i].second == A[j].second) continue;
        ll d = abs(A[j].first - A[i].first);

        for (int k = 1;k*k<=d;k++) if (!(d%k)) {
            U.insert(k);
            U.insert(d/k);
        }
    }

    FORN(i, 1, n) {
        if (U.count(i)) continue;
        vll T(i);
        REP(j, n){
            ll p = ((A[j].first%i) + i)%i;
            T[p] = A[j].second;
        }
        bool flag = false;
        REP(j, i) if (!T[j]) {
            flag = true;
            break;
        }
        if (flag) continue;

        FOR(j, 1, i) {
            if (i%j) continue;
            bool flag = false;
            REP(k, i) flag |= T[k] != T[k%j];
            if (!flag) {
                U.insert(i);
                break;
            }
        }
    }
    ll sum = 0, c=0;
    for (auto i: U) sum+=i, c++;
    cout<<c<<" "<<sum<<"\n";
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
