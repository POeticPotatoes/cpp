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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, x[N], y[N], a = -inf, b = inf, c = -inf, d = inf;
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		cin >> x[i] >> y[i];
		a = max(a, x[i] + y[i]);
		b = min(b, x[i] + y[i]);
		c = max(c, x[i] - y[i]);
		d = min(d, x[i] - y[i]);
	}
	if (n == 1) cout << "4\n";
	else if (a == b || c == d) cout << a - b + c - d + 5 << "\n";
	else cout << a - b + c - d + 4 << "\n";
	return 0;
}
