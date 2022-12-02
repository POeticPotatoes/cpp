#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
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

void solve() {
    ll n, q, i, j, x;
    cin >> n >> q;
    vector<bitset<30>> maxDoors(n), minDoors(n);
    REP(k,n) maxDoors[k].set();
    vvv<ll> mentions(n, vv<ll>(30));
    vector<bool> completed(n);

    REP(k, q) {
        cin>> i>> j >> x;
        i--, j--;
        if (i==j) {
            REP(s,30) {
                maxDoors[i][s]=(x&(1<<s));
                minDoors[i][s]=(x&(1<<s));
                completed[i]=1;
                continue;
            }
        }
        REP(s, 30) {
            if (!(x&(1<<s))) {
                maxDoors[i][s]=0;
                maxDoors[j][s]=0;
                continue;
            }
            mentions[i][s].eb(j);
            mentions[j][s].eb(i);
        }
    }

    REP(k, n) {
        if (completed[k]) continue;
        REP(s, 30) {
            if (!maxDoors[k][s]) continue;
            for (auto e: mentions[k][s]) {
                if ((completed[e] && !minDoors[e][s]) || !maxDoors[e][s]) {
                    minDoors[k][s] = 1;
                    break;
                }
            }
        }
        completed[k]=1;
    }

    cout<<minDoors[0].to_ullong();
    FOR(k,1, n)
        cout<<" "<<minDoors[k].to_ullong();
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin >> t;
    while (t--) solve();
}
