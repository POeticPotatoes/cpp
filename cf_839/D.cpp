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

ll A[200000], n, l, r;

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];
    l=-inf, r=inf;

    REP(i, n-1) {
        if (A[i] == A[i+1]) continue;
        if (A[i] < A[i+1]) {
            r = min(r, (A[i]+A[i+1])/2);
        } else {
            l = max(l, (A[i]+A[i+1]+1)/2);
        }
    }
    if (r<l) return (void) (cout<<-1<<endl);
    cout<<r<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
