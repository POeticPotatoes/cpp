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

ll N[41]{0,1,3,5}, s, n, A[41]{0,1,3,3};

void solve() {
    cin>>n;
    cout<<A[n]<<endl;
}

int main() {
    FOR(i, 4, 41) {
        N[i] = 2*N[i-2] + N[i-1];
        s = N[i/2];
        if (!(i&1)) s += 2*N[(i-2)/2];
        A[i] = (N[i] - s)/2 + s;
    }

    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
