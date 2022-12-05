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

const int N = 310000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int v1[N], v2[N], v3[N];
inline int lowbit(int x) {
	return x & -x;
}
void add(int v[], int x, int y) {
	for (int i = x; i < N; i += lowbit(i)) v[i] += y;
}
int get(int v[], int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += v[i];
	return res;
}
int n, v[N], a[N], b[N], pos[N];
PII c[N], d[N];
LL ans;
const int L = 200000;
vector<PII> sol;
set<int> S;
int main() {
	IO;
	cin >> n;
	repn(i, 1, n) cin >> a[i], c[i] = mp(a[i], i), add(v1, i, 1), pos[i] = i, S.insert(i);
	repn(i, 1, n) cin >> b[i], d[i] = mp(b[i], i), add(v2, i, 1);
	sort(c + 1, c + n + 1);
	sort(d + 1, d + n + 1);
	int l = 1;
	while (l <= n) {
		int r = l;
		while (c[l].se < d[l].se && r + 1 <= n && c[r + 1].fi == c[l].fi && c[r + 1].se < d[r + 1].se) r++;
		reverse(c + l, c + r + 1);
		reverse(d + l, d + r + 1);
		l = r + 1;
	}
	repn(i, 1, n) {
		int spos = c[i].se, sr = get(v1, c[i].se);
		int tpos = d[i].se, tr = get(v2, d[i].se);
		int cnt = abs(tr - sr);
		if (sol.size() < L) {
			vector<int> seq;
			auto it = S.lower_bound(c[i].se);
			if (sr <  tr) {
				auto it2 = it; it2++;
				while (sol.size() < L && cnt) {
					sol.pb(mp(pos[*it], pos[*it2]));
					swap(pos[*it], pos[*it2]);
					cnt--;
					it2++;
				}
			}
			else if (sr > tr) {
				auto it2 = it; it2--;
				while (sol.size() < L && cnt) {
					sol.pb(mp(pos[*it], pos[*it2]));
					swap(pos[*it], pos[*it2]);
					cnt--;
					it2--;
				}
			}
			
		}
		ans += abs(tr - sr);
		add(v1, c[i].se, -1);
		add(v2, d[i].se, -1);
		add(v3, c[i].se, -1);
		add(v3, d[i].se, 1);
		S.erase(c[i].se);
	}
	cout << ans << "\n";
	for (auto p: sol) cout << p.fi << " " << p.se << "\n";
	return 0;
}
