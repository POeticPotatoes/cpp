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

const int L = 500;
int n, v[N], num[N], freq[L][N], cur[L], l[N], r[N], cnt, bv[N];
vector<int> g[N];

void dfs(int x, int fa) {
	l[x] = ++cnt;
	bv[cnt] = v[x];
	for (auto y: g[x]) {
		if (y != fa) dfs(y, x);
	}
	r[x] = cnt;
}

const int B = 10000;
struct query {
	int l1, r1, l2, r2, id;
	friend bool operator < (query a, query b) {
		if (a.l1 / B != b.l1 / B) return a.l1 / B < b.l1 / B;
		if (a.r1 / B != b.r1 / B) return a.r1 / B < b.r1 / B;
		if (a.l2 / B != b.l2 / B) return a.l2 / B < b.l2 / B;
		return a.r2 < b.r2;
	}
}a[N];
int q, ans[N];
void inc(int x) {
	x = bv[x];
	int idx = x / L;
	freq[idx][num[x]]--;
	num[x]++;
	freq[idx][num[x]]++;
	if (freq[idx][cur[idx] + 1]) cur[idx]++;
}
void dec(int x) {
	x = bv[x];
	int idx = x / L;
	freq[idx][num[x]]--;
	num[x]--;
	freq[idx][num[x]]++;
	if (!freq[idx][cur[idx]]) cur[idx]--;
}
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) cin >> v[i];
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1, 0);
	cin >> q;
	repn(i, 1, q) {
		int x, y;
		cin >> x >> y;
		a[i] = {l[x], r[x], l[y], r[y], i};
	}
	sort(a + 1, a + q + 1);
	int r1 = 0, l1 = 1, r2 = 0, l2 = 1;
	repn(i, 1, q) {
		while (l1 > a[i].l1) inc(--l1);
		while (r1 < a[i].r1) inc(++r1);
		while (l2 > a[i].l2) inc(--l2);
		while (r2 < a[i].r2) inc(++r2);
		while (l1 < a[i].l1) dec(l1++);
		while (r1 > a[i].r1) dec(r1--);
		while (l2 < a[i].l2) dec(l2++);
		while (r2 > a[i].r2) dec(r2--);
		int mx = 0;
		rep(j, 0, L) mx = max(mx, cur[j]);
		rep(j, 0, L) {
			if (cur[j] == mx) {
				int base = j * L;
				rep(k, 0, L) {
					if (num[base] == mx) {
						ans[a[i].id] = base;
						break;
					}
					base++;
				}
				break;
			}
		}
	}
	repn(i, 1, q) cout << ans[i] << "\n";	 
	return 0;
}
