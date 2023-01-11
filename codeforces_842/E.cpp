#include <bits/stdc++.h>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
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

ll n, m, one, two, thr, a, b, c;

void solve() {
    cin>>n>>m;
    one = 1;
    FOR(i, 2, n) {
        one = (one*i)%m;
        cout<<i<<endl;
    }
    two = one;
    FOR(i, n+1, n*2) {
        two = (two*i)%m;
        cout<<i<<endl;
    }
    thr = two;
    FOR(i, n*2+1, n*3) {
        thr = (thr*i)%m;
        cout<<i<<endl;
    }
    a = one-1;
    b = ((two-one+m)%m*2)%m;
    c = (thr - b - a + m)%m;

    cout << (a+b+2*c)%m <<endl;
}

int main() {
    IO;
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
