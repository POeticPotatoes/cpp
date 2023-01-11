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

int T, n;
LD g, w[N], p[N];
LD sqr(LD x) {
	return x * x;
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> g;
		LD sum = 0;
		repn(i, 1, n) cin >> w[i], sum += sqr(w[i]);
		sum = sqrtl(sum);
		LD coef = 0, cons = 0;
		repn(i, 1, n) {
			LD x, y;
			cin >> x >> y;
			coef += x, cons += y;
		}
		if (cons < eps) {
			cout << fixed << setprecision(15) << 0 << "\n";
			continue;
		}
		LD t = cons / (g * sum - coef);
		t = max(t, (LD)0);
		cout << fixed << setprecision(15) << t << "\n";
	}	
	return 0;
}
