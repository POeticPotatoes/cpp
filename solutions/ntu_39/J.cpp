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

int n, pp[N], a[N], b[N];
const int L = 720;
void work(int x, int y) {
	if (x > y) swap(x, y);
	if (y - x == 360) {
		rep(i, 0, L) pp[i] = 1;
	}
	if (y - x > 360) swap(x, y);
	pp[x] = 1;
	while (x != y) {
		x = (x + 1) % L;
		pp[x] = 1;
	}
}
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) {
		cin >> a[i] >> b[i];
		b[i] = (b[i] + 180) * 2;
	}
	rep(i, 1, n) work(b[i], b[i + 1]);
	work(b[n], b[1]);
	int flag = 0, pos;
	rep(i, 0, L) if (!pp[i]) {
		flag = 1;
		pos = i;
		break;
	}
	
	if (flag) printf("no %.1lf", (double)pos / 2.0 - 180);
	else printf("yes\n");
	return 0;
}
