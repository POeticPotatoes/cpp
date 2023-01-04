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

char l[100], c, k;
ll a, t[128], vis[128], x;

void solve() {
    memset(vis, 0, sizeof(vis));
    a = 0;
    um<char, vector<char>> adj;
    MaxHeap<pair<ll, char>> q;

    // Read input
    REP(i, 28) {
        fgets(l, 100, stdin);
        if (strlen(l)<3) break;
        stringstream ss(l);
        ss>>c;
        ss>>t[(int) c];
        while (ss>>k)
            adj[c].eb(k);
        q.push({t[(int) c], c});
    }

    /*for (auto p: adj) {
        cout<<p.first<<" ("<<t[(int) p.first]<<"): ";
        for (auto j: p.second)
            cout<<j<<" ";
        cout<<endl;
    }*/

    while (q.size()) {
        c = q.top().second;
        x = q.top().first; q.pop();
        if (vis[(int) c] && vis[(int) c]>=x) continue;
        vis[(int) c] = x;
        a = max(a, x);

        for (auto j: adj[c])
            q.push({x+t[(int) j], j});
    }
    cout<<a<<endl;
}

int main() {
    int _=1;
    scanf("%d", &_);
    scanf("\n");
    while (_--) {
        solve();
        if (_) cout<<endl;
    }
}
