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

const int N = 11000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int T, n, m, k, pp[N];
string s[N];
map<string, int> S;
stack<int> now, rest;
void work() {
	if (k == 0 || now.empty() || rest.empty()) return;
	int t1 = rest.top(); rest.pop();
	work();
	int t2 = now.top(); now.pop();
	rest.push(t2);
	if (k) printf("%d %d\n", t2, t1), k--;
	work();
	now.push(t1);
}
int main() {
	IO;
	cin >> T;
	while (T--) {
		S.clear();
		cin >> m >> k >> n; k--;
		repn(i, 1, n) cin >> s[i], S[s[i]] = i, pp[i] = 0;
		while (!now.empty()) now.pop();
		while (!rest.empty()) rest.pop();
		repn(i, 1, m) {
			string t;
			cin >> t;
			now.push(S[t]);
			pp[S[t]] = 1;
		}
		repn(i, 1, n) if (!pp[i]) rest.push(i);
		work();
		if (T) cout << "\n";
	}
	return 0;
}
