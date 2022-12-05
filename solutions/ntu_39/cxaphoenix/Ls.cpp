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

int n, x, k;
int main() {
	IO;
	cin >> n >> x >> k;
	double ans = 0;
	ans = pow(1.0 / n, k) * x;
	repn(p, 2, n) {
		double res = 1.0 / (double)(n);
		res = res / (1 - (double)p / (p - 1));
		// res = res * pow((double)(p - 1) / n, k - 1);
		// res = res * (1 - pow(double(p) / (double)(p - 1), k));
		double r1 = res * pow((double)(p - 1) / n, k - 1);
		double r2 = res * pow((double)p / n, k - 1) * p / (p - 1);
		res = r1 - r2;
		if (p < x) res = res * x;
		else res = res * (p + 1) / 2.0;
		ans += res;
	}
	printf("%.10f\n", ans);
	return 0;
}
