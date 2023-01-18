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
constexpr ll N = 3e5;

ll n, m, a, b;
bitset<N> A[17];
string s;

void solve() {
    cin>>m>>n;
    REP(i, m) {
        cin>>s;
        A[i] = bitset<N>(s);
    }
    if (m==1) return (void) (cout<<"1"<<endl);
    FOR(i, 2, m) A[1] &= A[i];
    A[1].flip();
    A[0] &= A[1];
    a = A[0].count(), b=n-a;

    ld ans = 1;
    for(int i=2;i<=b;i++) ans *= i;
    for(int i=a+1;i<=n;i++) ans /= i;
    printf("%.10Lf\n", ans);
}

int main() {
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
