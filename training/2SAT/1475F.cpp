#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 0, (n))
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
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

// Set bits based on first row and check if valid
bool init(ll n, vector<string> &a, vector<string> &b, bool flag) {
    vector<bool> s(n);
    REP(i,n) s[i] = (b[0][i]=='1')^flag^(a[0][i]=='1');
    FOR(i, 1, n) {
        flag = (b[i][0]=='1')^s[0]^(a[i][0]=='1');
        REP(j,n) {
            if (flag ^ (b[i][j]=='1') ^ s[j] ^ (a[i][j]=='1'))
                return false;
        }
    }
    return true;
}

void solve() {
    ll n;
    cin>>n;
    vector<string> a(n), b(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];

    cout<< ((init(n,a,b,true) || init(n,a,b,false))?"YES":"NO")<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while (t--) solve();
}
