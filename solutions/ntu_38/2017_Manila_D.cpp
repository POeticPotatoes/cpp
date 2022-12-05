#include<bits/stdc++.h
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
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;

const int N = 4100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int T, n, m;
string s;
struct Trie {
	int pos, ch[N][26], val[N], root;
	PII g[N][26];
	int newnode() {
		pos++, memset(ch[pos], 0, sizeof(ch[pos])), val[pos] = 0, memset(g[pos], 0, sizeof(g[pos]));
		return pos;
	}
	void init() {
		pos = 0;
		root = newnode();
	}
	void insert(string &t) {
		int cur = 1;
		int n = t.size();
		rep(i, 0, n) {
			if (ch[cur][t[i] - 'A']) cur = ch[cur][t[i] - 'A'];
			else {
				ch[cur][t[i] - 'A'] = newnode();
				cur = ch[cur][t[i] - 'A'];
			}
		}
		val[cur] = 1;
	}
	void compress() {
		repn(i, 1, pos) {
			int nu = 0;
			rep(k, 0, 26) {
				if (ch[i][k]) g[i][nu++] = mp(k, ch[i][k]);
			}
		}
	}		
}A;
int pp[N][N], cp[N][N];

deque<PII> que;
void update(int nx, int ny, int cost, int w) {
	if (pp[nx][ny] == 0 || pp[nx][ny] > cost) {
		pp[nx][ny] = cost;
		if (w == 0) que.push_front(mp(nx, ny));
		else que.push_back(mp(nx, ny));
	}
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		A.init();
		repn(i, 1, n) {
			string t;
			cin >> t;
			A.insert(t);
		}
		A.compress();
		cin >> s;
		m = s.size();
		repn(i, 0, m) repn(j, 1, A.pos) {
			pp[i][j] = cp[i][j] = 0;
		}
		pp[0][1] = 1;
		while (!que.empty()) que.pop_front();
		que.push_front(mp(0, 1));
		while (!que.empty()) {
			auto now = que.front(); que.pop_front();
			int x = now.fi, y = now.se;
			if (cp[x][y]) continue;
			cp[x][y] = 1;
			if (A.val[y]) update(x, 1, pp[x][y], 0);
			if (x < m) update(x + 1, y, pp[x][y] + 1, 1);
			rep(i, 0, 26) {
				int k = A.g[y][i].fi, pos = A.g[y][i].se;
				if (pos == 0) break;		
				update(x, pos, pp[x][y] + 1, 1);
				if (x < m) {
					int w = (k != s[x] - 'A');
					update(x + 1, pos, pp[x][y] + w, w);
				}
			}
				
		}
		cout << pp[m][1] - 1 << "\n";
	}
	return 0;
}