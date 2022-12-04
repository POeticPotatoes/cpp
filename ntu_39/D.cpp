#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
template <typename T>
using t3 = tuple<T,T,T>;
template <typename T>
using t4 = tuple<T,T,T,T>;
typedef vector<ll> vl;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vv<T>>;
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 0, (n))
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
#define em emplace
#define mp make_pair
#define um unordered_map
#define lb_pos(arr, key) lower_bound(all(arr), key) - (arr).begin()
#define ub_pos(arr, key) upper_bound(all(arr), key) - (arr).begin()
#define FILL(arr, num) memset(arr, num, sizeof(arr))
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#define err(...)
#endif
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>19(a, b)(rng)
#define MAX  100000000000
#define MIN -100000000000

const int coeff[]{1, -1, 1, -1};

int g(int i) { return (i+4)%4; }

void solve() {
    ll n, x, y, range[]{MIN,MIN,MAX,MAX};
    cin>>n;
    if (n==1) {
        cout<<4<<endl;
        return;
    }
    while(n--) {
        cin>>x>>y;
        REP(i, 4) {
            ll c = (y-(x*coeff[i]));
            if (i<2) range[i] = max(range[i], c+1);
            else range[i] = min(range[i], c-1);
        }
    }
    // REP(i, 4)
    //     printf("%d ", range[i]);
    // cout<<endl;
    if (range[0]-range[2] <= 2) range[2]--;
    if (range[1]-range[3] <= 2) range[3]--;

    float ans=0;
    REP(i, 4) {
        ans += abs((range[g(i-1)]-range[g(i+1)])/2.0);
    }
    cout<<(long long) ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin >> t;
    while (t--) solve();
}
