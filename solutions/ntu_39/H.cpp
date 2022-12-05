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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n;
LL s[N], t[N], mx;
struct CartesianTree {
	int n, root;
	PIL p[N];
	int ch[N][2];
	LL sum[N];
	void build() {
		sort(p + 1, p + n + 1);
		p[n + 1] = mp(n + 1, INF);
		repn(i, 1, n) ch[i][0] = ch[i][1] = 0;
		stack<PIL> st;
		repn(i, 1, n + 1) {
			int last = 0;
			while (!st.empty() && st.top().se < p[i].se) {
				auto x = st.top(); 
				st.pop();
				if (last) ch[x.fi][1] = last;
				last = x.fi;
			}
			ch[p[i].fi][0] = last;
			st.push(p[i]);
		}
		root = ch[n + 1][0];
	}
	void work(int x) {
		sum[x] = p[x].se;
		if (ch[x][0]) work(ch[x][0]), sum[x] += sum[ch[x][0]];
		if (ch[x][1]) work(ch[x][1]), sum[x] += sum[ch[x][1]];
	}
		
	LL dfs(int x, LL v) {
		LL mn = p[x].se;
		if (ch[x][0]) mn = min(mn, dfs(ch[x][0], max(v, p[x].se - sum[ch[x][0]])));
		if (ch[x][1]) mn = min(mn, dfs(ch[x][1], max(v, p[x].se - sum[ch[x][1]])));
		mn = max(mn, v);
		return mn;
	}
}A;

int main() {
	IO;
	cin >> n;
	repn(i, 1, n) cin >> s[i], mx = max(mx, s[i]);
	repn(i, 1, n) if (s[i] == mx) {
		int cnt = 0;
		repn(j, i, n) t[++cnt] = s[j];
		repn(j, 1, i - 1) t[++cnt] = s[j];
		break;
	}
	A.n = n;
	repn(i, 1, n) A.p[i] = mp(i, t[i]);
	A.build(); A.work(A.root);
	cout << A.dfs(A.root, 0) << "\n";
	return 0;
}
