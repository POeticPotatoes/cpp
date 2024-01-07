#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
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

const ll MOD[] = {999727999, 1070777777, 1000000007, 998244353};
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
const int M = MOD[2];
const int inf = (int)1e9;
const ll INF = 1e18;

vector<int> adj[1005];
int mark[1005] = {0};
int cnt[1005] = {0};
int depth[1005] = {0};

int dfs(int node, int prv, int d) {
    depth[node] = d;
    int tot = mark[node];
    for(auto x:adj[node]) {
        if(x==prv) continue;
        tot += dfs(x, node, d+1);
    }
    return cnt[node] = tot;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    
    for(int i=0;i<q;i++) {
        int k, m;
        cin >> k >> m;
        memset(mark, 0, sizeof(mark));
        memset(cnt, 0, sizeof(cnt));
        memset(depth, 0, sizeof(depth));
        for(int j=0;j<m;j++) {
            int x;
            cin >> x;
            mark[x] = 1;
        }
        dfs(1,-1,0);
        
        // REP(j,n) {
        //     cout << cnt[j] << " ";
        // }
        // cout << endl;

        int mxd = 0;
        int num = 0;
        for(int j=1;j<=n;j++) {
            if(cnt[j]>=k) {
                if(depth[j]>mxd) {
                    mxd = depth[j];
                    num = 1;
                }
                else if(depth[j]==mxd) num++;
            }
        }
        cout << num << endl;
    }

    REP(j,n+1) adj[j].clear();
}

int main() {
    IO;
    int t=1;
    cin >> t;
    while (t--) solve();
}
