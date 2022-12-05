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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int ed, st, num = 1, d[N], now[N];
int e[M], pre[M], last[N], f[M];
void insert(int x, int y, int z) {
	e[++num] = y, f[num] = z, pre[num] = last[x], last[x] = num;
	e[++num] = x, f[num] = 0, pre[num] = last[y], last[y] = num;
}
queue<int> q;
bool bfs() {
    memset(d, -1, sizeof(d));
    d[st] = 0;
	q.push(st);
    while(!q.empty()) {
        int now = q.front();
        for (int i = last[now]; i; i = pre[i]) if (f[i] && d[e[i]] == -1) {
                d[e[i]] = d[now] + 1;
                q.push(e[i]); 
            }
        q.pop();
    }
    if (d[ed] == -1) return 0;
	return 1;
}
int dfs(int x, int incf) {
    if (x == ed) return incf;
    int flow = 0, w;
    for (int i = now[x]; i; i = pre[i]) if (f[i] && d[e[i]] == d[x] + 1) {
			w = dfs(e[i], min(incf - flow, f[i]));
            f[i] -= w, f[i^1] += w; flow += w;
            if (f[i]) now[x] = i;
			if (flow == incf) return incf;
        }
    if (!flow) d[x] = -1;
    return flow;
}
int dinic() {
	int maxflow = 0;
	while (bfs()) {
		for (int i = st; i <= ed; i++) now[i] = last[i];
		maxflow += dfs(st, 1e9);
	}
	return maxflow;	
}

int T, n, m;
int idx[110][110], g[110][110];
PII pos[N];
const int wayx[4] = {0, 0, 1, -1};
const int wayy[4] = {1, -1, 0, 0};
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		num = 1;
		repn(i, 0, n + 1) repn(j, 0, m + 1) g[i][j] = -1;
		repn(i, 1, n) {
			string s;
			cin >> s;
			repn(j, 1, m) {
				if (s[j - 1] == 'W') g[i][j] = 0;
				else if (s[j - 1] == 'I') g[i][j] = 1;
				else g[i][j] = 2;
				idx[i][j] = (i - 1) * m + j;
				pos[idx[i][j]] = mp(i, j);
			}
		}
		st = 0, ed = 2 * n * m + 1;
		repn(i, st, ed) last[i] = 0;
		repn(i, 1, n) repn(j, 1, m) {
			int id = idx[i][j];
			insert(id * 2 - 1, id * 2, 1);
			if (g[i][j] == 0) {
				insert(st, id * 2 - 1, 1);
				rep(k, 0, 4) {
					int nx = i + wayx[k], ny = j + wayy[k];
					if (g[nx][ny] == 1) insert(id * 2, idx[nx][ny] * 2 - 1, 1);
				}
			}
			else if (g[i][j] == 1) {
				rep(k, 0, 4) {
					int nx = i + wayx[k], ny = j + wayy[k];
					if (g[nx][ny] == 2) insert(id * 2, idx[nx][ny] * 2 - 1, 1);
				}
			}
			else insert(id * 2, ed, 1);
		}
		cout << dinic() << "\n";
		repn(i, 1, n) {
			repn(j, 1, m) {
				int id = idx[i][j];
				if (g[i][j] != 0) continue;
				int flag;
				for (int k = last[2 * id - 1]; k; k = pre[k]) {
					if (e[k] == 2 * id) {
						if (f[k] == 0) flag = 1;
						else flag = 0;
						break;
					}
				}
				if (!flag) continue;
				cout << i << " " << j << " ";
				int x, y;
				for (int k = last[2 * id]; k; k = pre[k]) {
					if (f[k] == 0) {
						int iid = (e[k] + 1) / 2;
						x = pos[iid].fi, y = pos[iid].se;
						cout << x << " " << y << " ";
						break;
					}
				}
				id = idx[x][y];
				for (int k = last[2 * id]; k; k = pre[k]) {
					if (f[k] == 0) {
						int iid = (e[k] + 1) / 2;
						x = pos[iid].fi, y = pos[iid].se;
						cout << x << " " << y << "\n";
						break;
					}
				}
			}
		}
	}
	return 0;
}