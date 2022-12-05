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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int f[M], n, m, h, q;
int ans[N];
pair<LL, int> a[N];
int main() {
	IO;
	cin >> n >> m >> h >> q;
	repn(i, 1, n) repn(j, 1, m) {
		int x;
		cin >> x;
		f[x]++;
	}
	repn(i, 1, q) {
		cin >> a[i].fi, a[i].se = i;
	}
	sort(a + 1, a + q + 1);
	int ch = 0;
	LL sum = 0, num = f[0];
	repn(i, 1, q) {
		LL v = a[i].fi;
		int id = a[i].se;
		while ((ch + 1) * num - sum <= v) ch++, num += f[ch], sum += f[ch] * (LL)ch;
		if (ch * num - sum == v) ans[id] = num - f[ch];
		else ans[id] = num;
	}
	repn(i, 1, q) cout << (LL)n * m - ans[i] << "\n";
	return 0;
}