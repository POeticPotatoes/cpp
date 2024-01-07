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

ll a[2000005] = {0};
ll b[2000005] = {0};
vector<int> primes;
vector<int> pows;
vector<int> apows[2000005];

void find_primes(int x) {
    for(int i=2;i<=sqrt(x);i++) {
        if(x%i == 0) {
            primes.eb(i);
            int cnt = 0;
            while(x%i == 0) {
                x /= i;
                cnt++;
            }
            pows.eb(cnt);
        }
    }
    if(x!=1) {
        primes.eb(x);
        pows.eb(1);
    }
}

ll gcd(ll x, ll y) {
    if(x==0) return x;
    return gcd(y%x, x);
}

void solve() {
    int n, x;
    cin >> n >> x;
    REP(i,n) cin >> a[i];
    find_primes(x);
    deb(primes);
    deb(pows);

    REP(i,n) {
        ll cur = 1;
        REP(j, primes.size()) {
            int cnt = 0;
            ll tmp = a[i];
            while(tmp%primes[j]==0) {
                tmp /= primes[j];
                cnt++;
            }

            REP(k, min(cnt,pows[j])) cur *=  primes[j];
        }
        b[i] = cur;
    }

    map<ll,ll> uniq;
    REP(i,n) uniq[b[i]]++;
    deb(uniq);
    
    map<ll,ll> dp;
    dp[1] = 0;
    for(auto [curr, cnt]: uniq) {
        map<ll, ll> nxt_dp = dp;
        deb(dp);
        
        for(auto [prod, val]: dp) {
            ll tmp = prod;
            FORN(i, 1, cnt) {
                ll tmp2 = gcd(tmp*curr, x);
                if(tmp2==tmp) break;
                tmp = tmp2;
                if(nxt_dp.count(tmp)) nxt_dp[tmp] = min(nxt_dp[tmp], val + i);
                else nxt_dp[tmp] = val + i;
            }
        }
        dp = nxt_dp;
    }
    deb(dp);
    if(dp.count(x)) cout << dp[x];
    else cout << -1;
    
}

int main() {
    IO;
    int t=1;
    // cin >> t;
    while (t--) solve();
}