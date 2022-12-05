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


string ans;
int last;
int get_time() {
	cout << ans << endl;
	fflush(stdout);
	string res;
	cin >> res;
	cin >> res;
	if (res == "GRANTED") {
		last = 0;
		return 0;
	}
	int tm = 0;
	cin >> res;
	rep(i, 1, res.size()) {
		tm = tm * 10 + res[i] - '0';
	}
	cin >> res;
	last = tm;
	return tm;
}
int main() {
	IO;
	while (1) {
		ans += "A";
		int res = get_time();
		if (res > 5 || res == 0) break;
	}
	while (last != 0) {
		int len = (last - 14) / 9, flag = 0, res, cur = last;
		rep(i, 0, 26) {
			if (flag) continue;
			ans[len] = 'A' + i;
			int res = get_time();
			if (res > cur || res == 0) flag = 1;
		}
		rep(i, 0, 26) {
			if (flag) continue;
			ans[len] = 'a' + i;
			int res = get_time();
			if (res > cur || res == 0) flag = 1;
		}
		rep(i, 0, 10) {
			if (flag) continue;
			ans[len] = '0' + i;
			int res = get_time();
			if (res > cur || res == 0) flag = 1;
		}
	}
	return 0;
}
