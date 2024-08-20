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

const ll N = 1e5;

void solve() {
    ll n;
    cin>>n;
    vll cnt(N+1), DP(N+1), lar(N+1);
    REP(i, n) {
        ll c;
        cin>>c;
        cnt[c]++;
    }

    ROF(i, N-1, 0) lar[i] = lar[i+1] + cnt[i+1];

    ll ans=0;
    ROF(i, N, 0) {
        ll cur=0;
        for (int j=i;j<=N;j+=i) {
            DP[i] -= DP[j];
            DP[i] += cur * cnt[j] * lar[j];
            DP[i] += cnt[j] * (cnt[j]-1) / 2 * (lar[j]+cur);
            DP[i] += cnt[j] * (cnt[j]-1) * (cnt[j]-2) / 6;
            deb(cur, j, DP[i], DP[j], cur, cnt[j], lar[j]);
            cur += cnt[j];
        }
        deb(i, DP[i]);
        ans += i * DP[i];
    }
    cout<<ans<<"\n";
}

int main() {
    IO;
    int t=1;
    cin >> t;
    while (t--) solve();
}
