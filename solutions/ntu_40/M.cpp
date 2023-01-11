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

const int N = 110;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

const int wayx[4] = {0, 0, 1, -1};
const int wayy[4] = {1, -1, 0, 0};
const char wayc[4] = {'R', 'L', 'D', 'U'};

int T, n, m, sx, sy, flag;
vector<int> ord;
string ans;
int vis[N][N];
int work() {
	memset(vis, 0, sizeof(vis));
	ans = "";
	int x = sx, y = sy;
	int num = n * m - 1;
	vis[x][y] = 1;
	repn(i, 1, num) {
		int flag = 0;
		rep(j, 0, 4) {
			int id = ord[j];
			int nx = x + wayx[id], ny = y + wayy[id];
			if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny]) continue;
			ans += wayc[id];
			x = nx, y = ny;
			flag = 1;
			vis[nx][ny] = 1;
			break;
		}
		if (!flag) return 0;
	}
	return 1;
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m >> sx >> sy;
		if (n == 1) {
			if (sy != 1 && sy != m) {
				cout << "IMPOSSIBLE\n";
				continue;
			}
		}
		if (m == 1) {
			if (sx != 1 && sx != n) {
				cout << "IMPOSSIBLE\n";
				continue;
			}
		}
		if (n * m % 2 == 1 && (sx + sy) % 2 == 1) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		ord = vector<int> {0, 1, 2, 3};
		repn(i, 1, 24) {
			int res = work();
			if (res) break;
			next_permutation(ord.begin(), ord.end());
		}
		cout << ans << "\n";
	}
	return 0;
}
