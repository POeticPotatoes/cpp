#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = (n) - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 21000;
const int M = 5100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int T, n, m, k;
int wayx[4] = {0, 0, 1, -1};
int wayy[4] = {1, -1, 0, 0};
struct node {
    int op, num, x, y;
};
int head = 1, tail;
node que[M];
int dis[9][51][N], f[N];
string s[N];
int sx, sy, ex, ey;
inline int cal(int x, int y) {
    return x * (m + 2) + y;
}
int main() {
    IO;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        rep(s, 0, 9) repn(i, 0, k) repn(j, 0, n + 1) repn(l, 0, m + 1) dis[s][i][cal(j, l)] = inf;
        repn(i, 0, n + 1) repn(j, 0, m + 1) f[cal(i, j)] = 0;
        repn(i, 1, n) {
            cin >> s[i];
            repn(j, 1, m) {
                if (s[i][j - 1] == '#');
                else if (s[i][j - 1] == 'A') f[cal(i, j)] = 1, sx = i, sy = j;
                else if (s[i][j - 1] == 'B') f[cal(i, j)] = 1, ex = i, ey = j;
                else if (s[i][j - 1] == 'D') f[cal(i, j)] = 2;
                else f[cal(i, j)] = 1;
            }
        }
        dis[8][0][cal(sx, sy)] = 0;
        head = 1, tail = 0;
        que[++tail] = {8, 0, sx, sy};
        while (head <= tail) {
            node now = que[head++];
            int op = now.op, num = now.num, x = now.x, y = now.y;
            if (x == ex && y == ey) break;
            int w = dis[op][num][cal(x, y)] + 1;
            // open door
            if (num < k) {
                rep(i, 0, 4) {
                    int nx = x + wayx[i], ny = y + wayy[i];
                    if (f[cal(nx, ny)] != 2) continue;
                    if (dis[i + 4][num + 1][cal(x, y)] == inf) dis[i + 4][num + 1][cal(x, y)] = w, que[++tail] = {i + 4, num + 1, x, y};
                }
            }
            // close door
            if (op < 4 && num) {
                int nx = x - wayx[op], ny = y - wayy[op];
                if (f[cal(nx, ny)] == 2) {
                    if (dis[8][num - 1][cal(x, y)] == inf) dis[8][num - 1][cal(x, y)] = w, que[++tail] = {8, num - 1, x, y};
                }
            }
            // move
            rep(i, 0, 4) {
                int nx = x + wayx[i], ny = y + wayy[i];
                if (f[cal(nx, ny)] == 0) continue;
                if (f[cal(nx, ny)] == 1 || f[cal(nx, ny)] == 2 && op - 4 == i) {
                    if (dis[i][num][cal(nx, ny)] == inf) dis[i][num][cal(nx, ny)] = w, que[++tail] = {i, num, nx, ny};
                }
            }
        }
        int ans = inf;
        rep(s, 0, 9) repn(i, 0, k) ans = min(ans, dis[s][i][cal(ex, ey)]);
        if (ans == inf) cout << "HAHAHUHU\n";
        else cout << ans << "\n";
    }
    return 0;
}
