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
constexpr int N = 1e5;

ll A[N], n, k, s, p;

void solve() {
    cin>>n>>k;
    REP(i, n) cin>>A[i];

    for(p=0, s=1;s<=n;s++) {
        while(A[p] != s) {
            p++;
            if (p==n) {
                cout<<(n-s+k)/k<<endl;
                return;
            }
        }
    }
    cout<<0<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
