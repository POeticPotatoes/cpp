#include <bits/stdc++.h>
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
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll i = (a); (i) > (b); (i)--)
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

int n,m;
vll p, ans, pos, vis;
vv<ll> adj;

int check(int x, int s) {
    int cur=0;
    ROF(i, n-1, vis[s]) {
        cur+=pos[i] - (i==x);
        if (!cur) return i;
        cur--;
    }
    return vis[s]+1;
}

void move(int a, int b) {
    pos[p[a]]--;
    p[a] = min(p[a], p[b]-1);
    pos[p[a]]++;
    
    for (auto i: adj[a]) move(i, a);
}

int deps(int a) {
    if (vis[a]!=-1) return vis[a];
    int sum=0;
    for (auto i:adj[a])
        sum+=deps(i)+1;
    vis[a] = sum;
    return sum;
}

void solve() {
    int a, b;
    cin>>n>>m;
    n++;
    ans = pos = p = vll(n);
    vis=vll(n, -1);
    adj = vv<ll>(n);
    FOR(i, 1, n) { 
        cin>>p[i];
        pos[p[i]]++;
    }

    REP(i, m) {
        cin>>a>>b;
        adj[b].eb(a);
        move(a,b);
    }

    FOR(i, 1, n) {
        deps(i);
        ans[i] = check(p[i], i);
    }
    
    cout<<ans[1];
    FOR(i, 2, n)
        cout<<" "<<ans[i];
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin >> t;
    while (t--) solve();
}
