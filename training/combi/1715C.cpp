#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
// #define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
// #define FORN(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
// #define ROF(i, a, b) for (ll i = (a); (i) > (b); (i)--)
// #define REP(i, n) FOR(i, 0, n)
// #define all(x) (x).begin(), (x).end()
// #define eb emplace_back
typedef long long ll;
// typedef long double ld;
// typedef vector<ll> vll;
// template <typename T>
// using vv = vector<vector<T>>;
// template <typename T>
// using vvv = vector<vv<T>>;
// template <typename T, typename N>
// using um = unordered_map<T, N>;
// template <typename T>
// using MinHeap = priority_queue<T, vector<T>, greater<T>>;
// template <typename T>
// using MaxHeap = priority_queue<T>;
// 
// constexpr int M = 1e9+7;
// constexpr int inf = (int)1e9;
// constexpr ll INF = 1e18;

const ll N = 2e5;

ll n, m, p, x, A[N], s;

void solve() {
    cin>>p>>x;
    if (A[p] != A[p-1]) s -= (p-1) * (n-p+1);
    if (A[p] != A[p+1]) s -= p * (n-p);
    A[p] = x;
    if (A[p] != A[p-1]) s += (p-1) * (n-p+1);
    if (A[p] != A[p+1]) s += p * (n-p);
    cout<<s<<endl;
}

int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>A[i];
    s = n*(n-1)/2 + n;
    for (int i=1;i<=n;i++) if (A[i]!=A[i+1])
        s += i * (n-i);
    while (m--) solve();
}
