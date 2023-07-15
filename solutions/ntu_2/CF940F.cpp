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
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 210000;
const int M = 210000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m, q, t, a[N], b[N], c[N], cnt, num;
map<int, int> S;

int col[M], freq[M];
void incp(int c) {
//	freq[col[c]]--;
//	if (freq[col[c]] == 0) sum[col[c] / B]--;
//	col[c]++;
//	freq[col[c]]++;
//	if (freq[col[c]] == 1) sum[col[c] / B]++;
	freq[col[c]++]--, freq[col[c]]++;
}
void decp(int c) {
//	freq[col[c]]--;
//	if (freq[col[c]] == 0) sum[col[c] / B]--;
//	col[c]--;
//	freq[col[c]]++;
//	if (freq[col[c]] == 1) sum[col[c] / B]++;
	freq[col[c]--]--, freq[col[c]]++;
}

const int L = 2200;
struct operation {
	int p, x, y;
}ops[N];
int ans[N];
struct query {
	int l, r, t, id;
	friend bool operator < (query a, query b) {
		if (a.l / L != b.l / L) return a.l / L < b.l / L;
		if (a.r / L != b.r / L) return a.r / L < b.r / L;
		return a.t < b.t;
	}
};
void tinc(int t, int l, int r) {
	int pos = ops[t].p, x = ops[t].x, y = ops[t].y;
	if (pos >= l && pos <= r) decp(x), incp(y);
	b[pos] = y;
}
void tdec(int t, int l, int r) {
	int pos = ops[t].p, x = ops[t].x, y = ops[t].y;
	if (pos >= l && pos <= r) decp(y), incp(x);
	b[pos] = x;
}
//void inc(int pos) {
//	incp(b[pos]);
//}
//void dec(int pos) {
//	decp(b[pos]);
//}
int getans() {
//	rep(i, 0, B) if (sum[i] != B) {
//		int ans = i * B;
//		rep(j, 0, B) if (freq[ans]) ans++;
//		return ans;
//	}
	rep(i, 1, M) if (freq[i] == 0) return i;
}
vector<query> qry;
void MoAlgo() {
	int l = 1, r = 0, t = 0;
	for (auto p: qry) {
		int pl = p.l, pr = p.r, pt = p.t, id = p.id;
		while (t < pt) tinc(++t, l, r);
		while (t > pt) tdec(t--, l, r);
		while (r < pr) incp(b[++r]);
		while (l > pl) incp(b[--l]);
		while (r > pr) decp(b[r--]);
		while (l < pl) decp(b[l++]);
		ans[id] = getans();
	}
}

int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, n) cin >> a[i], b[i] = a[i], c[++cnt] = a[i];
	repn(i, 1, m) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			qry.pb({l, r, t, ++q});
		}
		else {
			int p, x, y;
			cin >> p >> y;
			x = b[p];
			ops[++t] = {p, x, y};
			b[p] = y;
			c[++cnt] = y;
		}
	}
	sort(c + 1, c + cnt + 1);
	S[c[1]] = num = 1;
	repn(i, 2, cnt) if (c[i] != c[i - 1]) S[c[i]] = ++num;
	repn(i, 1, n) a[i] = S[a[i]];
	repn(i, 1, t) ops[i].x = S[ops[i].x], ops[i].y = S[ops[i].y];
	repn(i, 1, n) b[i] = a[i];
	sort(all(qry));
	MoAlgo();
	repn(i, 1, q) cout << ans[i] << "\n";
	return 0;
}
