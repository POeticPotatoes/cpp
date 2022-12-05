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
typedef pair<double, double> PDD;

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int T, n, a[N], flag;
LL ans;
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n;
		repn(i, 1, n) cin >> a[i];
		ans = flag = 0;
		repn(i, 1, n - 2) {
			if (a[i] & 1) {
				if (a[i + 1] == 0 || a[i + 2] == 0) {
					flag = 1;
					break;
				}
				a[i]--, a[i + 1]--, a[i + 2]--;
				ans++;
			}
		}
		if (flag || a[n - 1] % 2 == 1 || a[n] % 2 == 1) {
			cout << "no\n";
			continue;
		}
		repn(i, 1, n - 2) {
			LL d = min(min(a[i], a[i + 1]), a[i + 2]);
			ans += d;
			a[i] -= d, a[i + 1] -= d, a[i + 2] -= d;
		}
		repn(i, 1, n) ans += a[i] / 2;
		cout << ans << "\n";
	}
	return 0;
}