#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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

int r,c,k;
vector<string> m;
int xChange[]{1,-1,0,0}, yChange[]{0,0,1,-1};
vv<int> vis, ch, open;

bool check(int y, int x, int a, int b) {
    if ((a<0 || b<0 || a>=r || b>=c) || (k==1 && m[y][x] == 'D' && m[a][b]=='D')) return false;
    return m[a][b] != '#';
}

void solve() {
    cin>>r>>c>>k;
    vis = ch = open = vv<int>(r, vector<int>(c));
    m = vector<string>(r);

    REP(i, r) cin>>m[i];
    pair<int,int> pos;
    REP(y, r) REP(x, c) 
        if (m[y][x] == 'A') {
            pos={y,x};
            //cout<<"found agent at "<<y<<", "<<x<<endl;
            break;
        }

    queue<pair<int,int>> q;
    q.push({pos});
    vis[pos.first][pos.second] = 1;
    int ans = inf;

    while (q.size()) {
        auto cur = q.front();q.pop();
        int y = cur.first, x = cur.second, cost=vis[y][x]+1, o=open[y][x], a,b,d;
        ch[y][x] = 0;
        cout<<"exploring "<<y<<", "<<x<<endl;
        REP(i, 4) {
            a = y+yChange[i], b = x+xChange[i];
            if (!check(y, x, a, b)) continue;
            if (m[a][b] == 'B') {
                ans = min(ans, cost-1);
                break;
            }
            d = cost + (m[a][b] == 'D') * (1+(o==k));
            if (vis[a][b] && (vis[a][b] < d || (vis[a][b]==d && open[a][b]<=o))) continue;
            vis[a][b] = d;
            open[a][b] = min(k, o+(m[a][b]=='D'));
            // cout<<"setting "<<a<<", "<<b<<" to "<<d<<" ("<<open[a][b]<<endl;
            if (ch[a][b]) continue;
            ch[a][b] = 1;
            q.push({a,b});
        }
    }
    if (ans<inf) cout<<ans<<endl;
    else cout<<"HAHAHUHU"<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
