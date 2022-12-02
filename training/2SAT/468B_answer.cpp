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

ll n,a,b, cur;
map<ll, ll> all, A, B;
vector<ll> nums, visited, ans;

// Check if all numbers have their corresponding partners
bool check0() {
    REP(i,n) if (!all.count(a-nums[i])) return 0;
    return 1;
}

// (Not DP)
// Every dfs only attempts to place on one side 
//   (since if xAyBz and xAy, z be related to something under A)
// p is whether the number is the second element in a pair
// If so, it must check the opposing relation for any third item and attempt to place it
int dfs(int i, bool p, bool s) {
    visited[i] = 1;
    ans[i] = s;

    if (!p) {
        if (A[i]==i) return 1;
        if (A[i]==-1) return s;
        // cout<<"Linking "<<nums[i]<<" to "<<nums[A[i]]<<" under A"<<endl;
        return dfs(A[i], p^1, s);
    }

    if (B[i]==i) return 1;
    if (B[i]==-1) return s^1;
    // cout<<"Linking "<<nums[i]<<" to "<<nums[B[i]]<<" under B"<<endl;
    return dfs(B[i], p^1,s);
}

// This is the 2SAT magic
// Relies on the ASSUMPTION that known placements MUST be present
bool check1() {
    REP(i, n) {
        if (visited[i]) continue;

        // If the number is its own pair, ignore it
        if (A[i]==i||B[i]==i) continue;
        // If the number has multiple options skip it
        if (((A[i]==-1)^(B[i]==-1))==0) continue;

        // Else place it
        if (!dfs(i, A[i]==-1, A[i]==-1)) return 0;
    }

    // Fix any self loops
    REP(i,n) if (!visited[i]) {
        if (A[i]==i) {
            visited[i]=1, ans[i] = 0;
        } else if (B[i]==i) {
            visited[i]=1, ans[i] = 1;
        }
    }

    // If any other items remain an error must be thrown
    REP(i,n) if (!visited[i]) return 0;
    return 1;
}

void solve() {
    cin>>n>>a>>b;
    nums = vector<ll>(n);
    visited = vector<ll>(n);
    ans = vector<ll>(n);
    REP(i, n) {
        cin >> nums[i];
        all[nums[i]] = i;
    }
    if (a==b) {
        // If all numbers are paired return yes
        if (check0()) {
            cout<<"YES\n";
            cout<<0;
            FOR(i,1,n) cout<<" "<<0;
            cout<<endl;
            return;
        }
        cout<<"NO"<<endl;
        return;
    }
    
    // Create the 2SAT
    // If pair exists, put the corresponding number in the map
    // If pair doesn't exist, put -1
    REP(i, n) {
        A[i] = (all.count(a-nums[i]))? all[a-nums[i]] : -1;
        B[i] = (all.count(b-nums[i]))? all[b-nums[i]] : -1;
    }
    if (check1()) {
        cout<<"YES\n"<<ans[0];
        FOR(i,1,n)
            cout<<" "<<ans[i];
        cout<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin >> t;
    while (t--) solve();
}
