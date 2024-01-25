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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

const int L = 450;
struct query {
	int l, r, id;
	friend bool operator < (query a, query b) {
		if (a.l / L != b.l / L) return a.l / L < b.l / L;
		if ((a.l / L) & 1) return a.r > b.r;
		else return a.r < b.r;
	}
}a[N];
LL v[N], num[M];
LL ans[N], res;
int n, m;
void inc(int x) {
	LL val = v[x];
	res -= num[val] * num[val] * val;
	num[val]++;
	res += num[val] * num[val] * val;
}
void dec(int x) {
	LL val = v[x];
	res -= num[val] * num[val] * val;
	num[val]--;
	res += num[val] * num[val] * val;
}
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) cin >> v[i];
	repn(i, 1, m) {
		cin >> a[i].l >> a[i].r;
		a[i].id = i;
	}
	sort(a + 1, a + m + 1);
	int l = 1, r = 0;
	repn(i, 1, m) {
		while (r < a[i].r) inc(++r);
		while (l > a[i].l) inc(--l);
		while (r > a[i].r) dec(r--);
		while (l < a[i].l) dec(l++);
		ans[a[i].id] = res;
	}
	repn(i, 1, m) cout << ans[i] << "\n";
	return 0;
}
