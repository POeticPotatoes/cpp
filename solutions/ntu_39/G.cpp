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
typedef pair<ull, ull> PUU;

const int N = 5100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, w;
string s[N];
int f[N], dp[N], pre[N], len[N];
int check(int x) {
	memset(f, 0, sizeof(f));
	memset(dp, 0, sizeof(dp));
	repn(i, 1, n) {
		int mn = inf;
		rep(j, 0, i) {
			f[j] = max(f[j], len[i]);
			if (i - j <= x) {
				int cost = f[j] + dp[j] + (j != 0);
				if (cost < mn) {
					mn = cost;
					pre[i] = j;
				}
			}
		}
		dp[i] = mn;
	}
	return dp[n] <= w;
}
char g[5100][5100];
int main() {
	IO;
	cin >> n >> w;
	repn(i, 1, n) cin >> s[i], len[i] = s[i].size();
	int l = 1, r = n, ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	check(ans);
	vector<int> col;
	int cur = n;
	while (cur) col.pb(cur - pre[cur]), cur = pre[cur];
	reverse(all(col));
	repn(i, 1, ans) repn(j, 1, w) g[i][j] = ' ';
	cout << ans << " " << col.size() << "\n";
	cur = 0;
	int curw = 1;
	repn(i, 1, col.size()) {
		int mx = 0;
		repn(j, 1, col[i - 1]) {
			mx = max(mx, len[cur + j]);
			rep(k, 0, s[cur + j].size()) g[j][curw + k] = s[cur + j][k];
		}
		cur += col[i - 1];
		cout << mx;
		if (i != col.size()) cout << " ";
		else cout << "\n";
		curw += mx + 1;
	}
	repn(i, 1, ans) cout << g[i] + 1 << "\n";
	return 0;
}
