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
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 1100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int T, n, m;
int pp[N][N], f[N][N], sx, sy, ex, ey;

int main() {
    IO;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        sx = sy = 0;
        repn(i, 0, n + 1) repn(j, 0, m + 1) pp[i][j] = 0, f[i][j] = 1;
        repn(i, 1, n) {
            string s;
            cin >> s;
            repn(j, 1, m) {
                if (s[j - 1] == '#') f[i][j] = 1;
                else
                {
                    f[i][j] = 0;
                    if (s[j - 1] == 'O') ex = i, ey = j;
                    if (s[j - 1] == 'Y' && sx == 0) sx = i, sy = j;
                }
            }
        }
        pp[sx][sy] = 1;
        queue<PII> que;
        que.push(mp(sx, sy));
        int ans = 0;
        while (!que.empty()) {
            PII now = que.front();
            int x = now.fi, y = now.se;
            que.pop();
            if (mp(x, y) == mp(ex, ey)) ans = pp[x][y];
            if (mp(x + 1, y) == mp(ex, ey)) ans = pp[x][y];
            if (mp(x, y + 1) == mp(ex, ey)) ans = pp[x][y];
            if (mp(x + 1, y + 1) == mp(ex, ey)) ans = pp[x][y];
            if (ans) break;
            // up
            if (f[x - 1][y] || f[x - 1][y + 1]);
            else if (!pp[x - 1][y]) pp[x - 1][y] = pp[x][y] + 1, que.push(mp(x - 1, y));
            // upright
            if (f[x - 1][y] || f[x - 1][y + 1] || f[x - 1][y + 2] || f[x][y + 2] || f[x + 1][y + 2]);
            else if (!pp[x - 1][y + 1]) pp[x - 1][y + 1] = pp[x][y] + 1, que.push(mp(x - 1, y + 1));
            // right
            if (f[x][y + 2] || f[x + 1][y + 2]);
            else if (!pp[x][y + 1]) pp[x][y + 1] = pp[x][y] + 1, que.push(mp(x, y + 1));
            // right down
            if (f[x][y + 2] || f[x + 1][y + 2] || f[x + 2][y] || f[x + 2][y + 1] || f[x + 2][y + 2]);
            else if (!pp[x + 1][y + 1]) pp[x + 1][y + 1] = pp[x][y] + 1, que.push(mp(x + 1, y + 1));
            // down
            if (f[x + 2][y] || f[x + 2][y + 1]);
            else if (!pp[x + 1][y]) pp[x + 1][y] = pp[x][y] + 1, que.push(mp(x + 1, y));
            // down left
            if (f[x][y - 1] || f[x + 1][y - 1] || f[x + 2][y - 1] || f[x + 2][y] || f[x + 2][y + 1]);
            else if (!pp[x + 1][y - 1]) pp[x + 1][y - 1] = pp[x][y] + 1, que.push(mp(x + 1, y - 1));
            // left
            if (f[x][y - 1] || f[x + 1][y - 1]);
            else if (!pp[x][y - 1]) pp[x][y - 1] = pp[x][y] + 1, que.push(mp(x, y - 1));
            // up left
            if (f[x - 1][y - 1] || f[x - 1][y] || f[x - 1][y + 1] || f[x][y - 1] || f[x + 1][y - 1]);
            else if (!pp[x - 1][y - 1]) pp[x - 1][y - 1] = pp[x][y] + 1, que.push(mp(x - 1, y - 1));
            
        }
        cout << ans - 1 << "\n";
    }    
    return 0;
}
