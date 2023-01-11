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
constexpr ll N = 2e5+1;

ll n, c, cur, A[N], vis[N];

void solve() {
    cin>>n;
    um<ll,ll> pos;
    FOR(i, 1, n) {
        cin>>A[i];
        pos[A[i]] = i;
    }
    memset(vis, 0, sizeof(vis));
    c=1;
    FOR(i, 1, n) {
        if (vis[i]) continue;
        vis[i] = c;
        cur = pos[i];
        while(cur != i) {
            vis[cur] = c;
            cur = pos[cur];
        }
        c++;
    }
    c--;
    FOR(i, 1, n-1) {
        if (vis[i] == vis[i+1])
            return (void) (cout<<n-c-1<<endl);
    }
    cout<<n-c+1<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
