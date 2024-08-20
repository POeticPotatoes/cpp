#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
// #define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
// #define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
// #define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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

ll n;
char A[N][4];
int remap[128];
const char chars[] = "win";

void solve() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    vector<int> adj[3][3];
    for(int i=0;i<n;i++) {
        vector<int> vis(3);
        for(int j=0;j<3;j++) vis[remap[A[i][j]]]++;
        for(int j=0;j<3;j++) if (vis[j]>1)
            for (int k=0;k<3;k++)
                if (!vis[k]) adj[j][k].emplace_back(i);
    }
    vector<tuple<int, char, int, char>> ans;
    for (int i=0;i<3;i++) for (int j=0;j<3;j++)
        while (adj[i][j].size() && adj[j][i].size()) {
            auto a = adj[i][j].back(), b = adj[j][i].back();
            ans.emplace_back(a, chars[i], b, chars[j]);
            adj[i][j].pop_back(), adj[j][i].pop_back();
        }
    
    while (adj[0][1].size()) {
        int a = adj[0][1].back(), b = adj[1][2].back(), c = adj[2][0].back();
        ans.emplace_back(a, 'w', b, 'i');
        ans.emplace_back(b, 'w', c, 'n');
        adj[0][1].pop_back();
        adj[1][2].pop_back();
        adj[2][0].pop_back();
    }
    while (adj[1][0].size()) {
        int a = adj[1][0].back(), b = adj[2][1].back(), c = adj[0][2].back();
        ans.emplace_back(a, 'i', c, 'w');
        ans.emplace_back(c, 'i', b, 'n');
        adj[1][0].pop_back();
        adj[2][1].pop_back();
        adj[0][2].pop_back();
    }
    cout<<ans.size()<<endl;
    for (auto [a, b, c, d]: ans)
        printf("%d %c %d %c\n", a+1, b, c+1, d);
}

int main() {
    int t=1;
    remap['w'] = 0;
    remap['i'] = 1;
    remap['n'] = 2;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
