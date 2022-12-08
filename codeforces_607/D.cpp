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

void solve() {
    int r, c;
    cin>>r>>c;
    vector<string> board(r);
    vv<int> count(r+1, vector<int>(c+1));
    REP(i,r) cin>>board[i];

    int total = 0;

    REP(y, r) REP(x, c) if (board[y][x] =='A') count[r][x]++, count[y][c]++, total++;

    if (total == r*c) {
        cout<<"0\n";
        return;
    }
    
    if (count[0][c]==c || count[r][0]==r || count[r-1][c] == c || count[r][c-1] == r) {
        cout<<"1\n";
        return;
    }
    if (board[0][c-1]=='A' || board[r-1][0]=='A' || board[0][0] == 'A' || board[r-1][c-1] == 'A') {
        cout<<"2\n";
        return;
    }
    REP (x, c) {
        if (count[r][x] == r) {
            cout<<"2\n";
            return;
        }
    }
    REP (y, r) {
        if (count[y][c] == c) {
            cout<<"2\n";
            return;
        }
    }
    if (count[0][c] || count[r][0] || count[r-1][c] || count[r][c-1]) {
        cout<<"3\n";
        return;
    }
    if (!total) {
        cout<<"MORTAL\n";
        return;
    }
    cout<<4<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin >> t;
    while (t--) solve();
}
