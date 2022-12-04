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

vll covered(722), result(722);

int convert(int a) {
    return (a+180)*2;
}

void move(int a, int b) {
    // cout<<"Moving from "<<a<< " to "<<b<<endl;
    if (b-a > 360) {
        // cout<<"moved through 0\n";
        covered[a+1]--;
        covered[0]++;
        covered[b]++;
        return;
    }
    covered[a]++;
    covered[b+1]--;
}

void solve() {
    int n, p, l, prev, cur, a, b, orig;
    cin>>n;
    cin>>p>>l;
    orig = prev = convert(l);
    FOR(i, 1, n) {
        cin>>p>>l;
        cur = convert(l);
        a = cur, b= prev;
        if (a>b) swap(a, b);
        if (b-a==360) {
            cout<<"yes\n";
            return;
        }
        move(a,b);
        prev = cur;
    }
    a = orig, b= prev;
    if (a>b) swap(a, b);
    if (b-a==360) {
        cout<<"yes\n";
        return;
    }
    move(a,b);

    int trav=0;
    REP(i, 720) {
        trav += covered[i];
        // cout<<"| i: "<<i<<" covered: "<<covered[i]<<" trav: "<<trav;
        result[i] = trav;
    }
    
    REP(i,360) {
        if (result[i]<1 && result[719-i]<1) {
            printf("no %.1f\n", ((360-i-1)/2.0));
            return;
        }
    }
    cout<<"yes\n";
}

int main() {
    int t=1;
    //cin >> t;
    while (t--) solve();
}
