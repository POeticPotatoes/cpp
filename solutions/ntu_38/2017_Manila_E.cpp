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
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, m, k, p;
int id[N], xu[N], num, fp[N], cp[N];
int pw[N];
vector<int> fin[N], fout[N];
LL f[51][51];

int pp[N]; 
vector<PIL> g[N];
priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL,int>>> q;
LL dis[N];

void dijkstra(int st) {
	repn(i, 0, n) dis[i] = INF, pp[i] = 0;
	dis[st] = 0;
	q.push(mp(0, st));
	while (!q.empty()) {
		int now = q.top().se; q.pop();
		if (pp[now]) continue;
		pp[now] = 1;
		for (auto p: g[now]) {
			int y = p.fi;
			LL w = p.se;
			if (dis[now] + w < dis[y]) dis[y] = dis[now] + w, q.push(mp(dis[y], y));
		}
	}
}
LL dp[210000][24];
void update(int s, int n, LL w) {
	if (dp[s][n] == -1 || dp[s][n] > w) dp[s][n] = w;
}
int final[210000];
int main() {
	IO;
	cin >> n >> m >> k >> p;
	pw[0] = 1;
	rep(i, 1, 15) {
		pw[i] = pw[i - 1] * 3;
	}
	repn(i, 1, m) {
		int x, y, c;
		cin >> x >> y >> c;
		g[x].pb(mp(y, c));
		g[y].pb(mp(x, c));
	}
	repn(i, 1, p) {
		int x;
		cin >> x;
		fp[x] = 1;
		g[x].pb(mp(0, 0));
		g[0].pb(mp(x, 0));
	}
	repn(i, 1, k) {
		int s, t;
		cin >> s >> t;
		if (!cp[s]) cp[s] = ++num, xu[num] = s;
		if (!cp[t]) cp[t] = ++num, xu[num] = t;
		fin[cp[s]].pb(pw[i - 1]);
		fout[cp[t]].pb(pw[i - 1]);
	}
	repn(i, 1, num) {
		dijkstra(xu[i]);
		repn(j, 1, n) {
			if (cp[j]) f[i][cp[j]] = dis[j];
			if (fp[j]) f[0][i] = dis[j];
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	rep(i, 0, pw[k]) {
		final[i] = 1;
		rep(j, 0, k) {
			if ((i / pw[j]) % 3 == 1) final[i] = 0;
		}
	}
	rep(i, 0, pw[k]) {
		pern(j, 0, num) {
			if (dp[i][j] == -1) continue;
			repn(y, 1, num) {
				vector<int> s;
				s.pb(i);
				for (auto x: fin[y]) {
					if ((i / x) % 3 == 0) {
						int tn = s.size();
						rep(l, 0, tn) s.pb(s[l] + x);
					}
				}
				for (auto ss: s) {
					int w = ss;
					for (auto x: fout[y]) {
						if ((ss / x) % 3 == 1) w += x;
					}
					if (w > i) {
						update(w, y, dp[i][j] + f[j][y]);
						if (final[w]) update(w, 0, dp[i][j] + f[j][y]);
					}
				}
			}
		}
	}
	cout << dp[pw[k] - 1][0] << "\n";
	return 0;
}