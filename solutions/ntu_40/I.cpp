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

const int N = 11000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, q, sz[N];
PII tmp[N];
string s;
vector<int> g[N];
PII dp[N][N];
PII operator + (PII a, PII b) {
	return mp(a.fi + b.fi, a.se + b.se);
}
void dfs(int x) {
	if (s[x - 1] == 'C') dp[x][1] = mp(1, 1);
	else dp[x][1] = mp(0, 0);
	sz[x] = 1;
	for (auto y: g[x]) {
		dfs(y);
		repn(i, 1, sz[x] + sz[y]) tmp[i] = mp(inf, 0);
		repn(i, 1, sz[x]) tmp[i] = dp[x][i];
		repn(i, 1, sz[x]) {
			repn(j, 1, sz[y]) {
				PII res = dp[x][i] + dp[y][j];
				tmp[i + j].fi = min(tmp[i + j].fi, res.fi);
				tmp[i + j].se = max(tmp[i + j].se, res.se);
			}
		}
		sz[x] += sz[y];
		repn(i, 1, sz[x]) dp[x][i] = tmp[i];
	}
}
		
int main() {
	IO;
	cin >> n >> q;
	repn(i, 1, n) {
		int x;
		cin >> x;
		if (x) g[x].pb(i);
	}
	cin >> s;
	dfs(1);
	while (q--) {
		int x, c, s;
		cin >> x >> c >> s;
		if (c + s > sz[x]) cout << "NOT COMPROMISED\n";
		else if (dp[x][c + s].fi <= c && dp[x][c + s].se >= c) cout << "COMPROMISED\n";
		else cout << "NOT COMPROMISED\n";
	}
	return 0;
}
