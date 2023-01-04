#include <bits/stdc++.h>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll n, k, i, j, o, a;

void solve() {
    n--;
    k = sqrt(n);
    o = 2*(k)+1;
    a = k*k;
    if (k&1) {
        if (n>a+o/2) return (void) (cout<<k+1<<" "<<a+o-n<<endl);
        return (void) (cout<<n-a+1<<" "<<k+1<<endl);
    }
    if (n>a+o/2) return (void) (cout<<a+o-n<<" "<<k+1<<endl);
    cout<<k+1<<" "<<n-a+1<<endl;
}

int main() {
    IO;
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (true) {
        cin>>n;
        if (!n) break;
        solve();
    }
}
