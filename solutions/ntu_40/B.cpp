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

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int T, n, m;
string s;
vector<string> ans;
int main() {
	IO;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cin >> s;
		ans.clear();
		if (m == 1) {
			string tmp = "";
			rep(i, 0, n) tmp += '0';
			rep(i, 0, n) if (s[i] == '0') {
				string cur = tmp;
				cur[i] = '1';
				ans.pb(cur);
			}
			cout << ans.size() << "\n";
			for (auto t: ans) cout << t << "\n";
			continue;
		}
		if (n == m) {
			int num = 0;
			rep(i, 0, n) if (s[i] == '0') num++;
			if (num == 0) cout << "0\n";
			else if (num == n) {
				string tmp = "";
				rep(i, 0, n) tmp += '1';
				cout << "1\n" << tmp << "\n";
			}
			else cout << "CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS\n";
			continue;
		}
		int num = 0;
		rep(i, 0, n) if (s[i] == '0') num++;
		if (m % 2 == 0 && num % 2 == 1) cout << "CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS\n";
		else {
			string tmp = "";
			rep(i, 0, n) tmp += '0';
			if (num % 2 == 1) {
				string cur = tmp;
				int flag = 0;
				rep(i, 0, m - 1) {
					if (s[i] == '0') flag = 1;
					cur[i] = '1', s[i] = ((s[i] - '0') ^ 1) + '0';
				}
				if (!flag) {
					rep(i, m - 1, n) if (s[i] == '0') {
						cur[i] = '1';
						s[i] = ((s[i] - '0') ^ 1) + '0';
						break;
					}
				}
				else cur[m - 1] = '1', s[m - 1] = ((s[m - 1] - '0') ^ 1) + '0';
				ans.pb(cur);
			}
			num = 0;
			rep(i, 0, n) if (s[i] == '0') num++;
			assert(num % 2 == 0);
			int cur = 0;
			repn(i, 1, num / 2) {
				while (s[cur] != '0') cur++;
				int x = cur;
				cur++;
				while (s[cur] != '0') cur++;
				int y = cur;
				cur++;
				string now = tmp;
				int rem = m - 1;
				rep(j, 0, n) {
					if (j != x & j != y && rem) now[j] = '1', rem--;
				}
				now[x] = '1';
				ans.pb(now);
				now[x] = '0';
				now[y] = '1';
				ans.pb(now);
			}
			cout << ans.size() << "\n";
			for (auto t: ans) cout << t << "\n";
		}
	}
	return 0;
}
