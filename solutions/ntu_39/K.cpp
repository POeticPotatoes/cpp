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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

map<string, int> S[3];
set<string> SS;
int n, sum;
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		string s, t;
		int num;
		cin >> s >> t >> num;
		if (t == "any") S[0][s] = num;
		else if (t == "left") S[1][s] = num;
		else S[2][s] = num;
		SS.insert(s);
		sum += num;
	}
	int ans = 0;
	for (auto p: SS) {
		int nany = S[0][p];
		int nleft = S[1][p];
		int nright = S[2][p];
		ans += max(nleft, nright);
		if (nright + nleft == 0) ans += min(nany, 1);
	}
	if (ans == sum) cout << "impossible\n";
	else cout << ans + 1 << "\n";
	return 0;
}
