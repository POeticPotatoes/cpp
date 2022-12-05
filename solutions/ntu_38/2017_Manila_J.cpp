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

int T;
int n, d, fc, fe;
char x;
char get() {
	char x;
	cin >> x;
	while (x != 'C' && x != 'E') cin >> x;
	return x;
}
void work(int nc, int ne, int n, int tp) {
	if (nc + ne > n) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	if (tp == 0) ne--;
	else nc--;
	repn(i, 1, n) cout << "R";
	cout << "\n";
	repn(i, 1, nc) cout << "S";
	repn(i, 1, ne) cout << "P";
	repn(i, 1, n - ne - nc - 1) cout << "R";
	if (tp == 0) cout << "P";
	else cout << "S";
	cout << "\n";
}
LL extended_gcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    else {
        LL r = extended_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}
LL inv(LL a, LL n) {
	LL xx, yy, d = extended_gcd(a, n, xx, yy);
	return (xx % n + n) % n;
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> d >> fc >> fe;
		x = get();
		if (x == 'C') {
			if (d < fc) {
				cout << "IMPOSSIBLE\n";
				continue;
			}
			else if (d == fc) {
				repn(i, 1, n) cout << "R";
				cout << "\n";
				repn(i, 1, n) cout << "R";
				cout << "\n";
				continue;
			}
			else {
				d -= fc + fe;
				int nc = 0, ne = 1;
				if (d < 0 || d % __gcd(fc, fe) > 0) {
					cout << "IMPOSSIBLE\n";
					continue;
				}
				int dd = __gcd(fc, fe);
				d /= dd, fc /= dd, fe /= dd;
				if (fc > fe) {
					int x = (LL)(d % fc) * inv(fe, fc) % fc;
					if (d < (LL)x * fe) {
						cout << "IMPOSSIBLE\n";
						continue;
					}
					int y = (d - (LL)x * fe) / fc;
					ne += x, nc += y;
				}
				else {
					int x = (LL)(d % fe) * inv(fc, fe) % fe;
					if (d < (LL)x * fc) {
						cout << "IMPOSSIBLE\n";
						continue;
					}
					int y = (d - (LL)x * fc) / fe;
					nc += x, ne += y;
				}
				work(nc, ne, n, 0);
			}
		}
		else {
			if (d < fe) {
				cout << "IMPOSSIBLE\n";
				continue;
			}
			else if (d == fe) {
				repn(i, 1, n) cout << "R";
				cout << "\n";
				repn(i, 1, n) cout << "R";
				cout << "\n";
				continue;
			}
			else {
				d -= fc + fe;
				int nc = 1, ne = 0;
				if (d < 0 || d % __gcd(fc, fe) > 0) {
					cout << "IMPOSSIBLE\n";
					continue;
				}
				int dd = __gcd(fc, fe);
				d /= dd, fc /= dd, fe /= dd;
				if (fc > fe) {
					int x = (LL)(d % fc) * inv(fe, fc) % fc;
					if (d < (LL)x * fe) {
						cout << "IMPOSSIBLE\n";
						continue;
					}
					int y = (d - (LL)x * fe) / fc;
					ne += x, nc += y;
				}
				else {
					int x = (LL)(d % fe) * inv(fc, fe) % fe;
					if (d < (LL)x * fc) {
						cout << "IMPOSSIBLE\n";
						continue;
					}
					int y = (d - (LL)x * fc) / fe;
					nc += x, ne += y;
				}
				work(nc, ne, n, 1);
			}
		}
	}
	return 0;
}