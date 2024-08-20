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

    vll pos(n);
    pos[n-1] = A[n-1].first;

    ROF(i, n-2, -1) {
        if (A[i].first<=pos[i+1] && A[i].second>=pos[i+1]) {
            pos[i] = pos[i+1];
            continue;
        }
        if (A[i].first>pos[i+1]) {
            pos[i] = A[i].first;
        } else
            pos[i] = A[i].second;
    }
    deb(pos);

    auto check = [&] (ll v) {
        ll p=0;
        REP(i, n) {
            // move in direction of pos[i];
            if (pos[i] > p)
                p = p + min(v, pos[i]-p);
            else
                p = p - min(v, p-pos[i]);
            
            if (p < A[i].first || p>A[i].second) return false;
        }
        return true;
    };

    ll l=0, r=1e9;
    while (l<r) {
        ll mid = (l+r)/2;
        if (check(mid)) r=mid;
        else l = mid+1;
    }
    cout<<l<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
