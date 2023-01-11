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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int T, n, m;
string s, t;
int dp[N][10]; // 5 - base +
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> s;
		cin >> t;
		n = s.size();
		m = t.size();
		repn(i, 0, n) rep(j, 0, 10) dp[i][j] = inf;
		if (abs(n - m) > 3) {
			cout << "What you entered is too different from the real password.\n";
			continue;
		}
		dp[0][5] = 0;
		repn(i, 0, n) {
			rep(delta, 0, 10) {
				int j = i + delta - 5;
				// add
				if (delta + 1 < 10) dp[i][delta + 1] = min(dp[i][delta + 1], dp[i][delta] + 1);
				// delete
				if (i < n && delta) dp[i + 1][delta - 1] = min(dp[i + 1][delta - 1], dp[i][delta] + 1);
				// equal
				if (i < n && j < m && s[i] == t[j]) dp[i + 1][delta] = min(dp[i + 1][delta], dp[i][delta]);
				// replace
				if (i < n && j < m) dp[i + 1][delta] = min(dp[i + 1][delta], dp[i][delta] + 1);
			}
		}
		int res = dp[n][5 + m - n];
		if (res > 3) cout << "What you entered is too different from the real password.\n";
		else if (res == 0) cout << "You're logged in!\n";
		else if (res == 1) cout << "You almost got it. You're wrong in just one spot.\n";
		else if (res == 2) cout << "You almost got it, but you're wrong in two spots.\n";
		else cout << "You're wrong in three spots.\n";
	}
	return 0;
}
