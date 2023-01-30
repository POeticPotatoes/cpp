#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
map<int, int> mp;
vector<int> fac;
int mu(int x) {
	if(mp.count(x)) return mp[x];
	int c = 1;
	for(auto i : fac) if(x % i == 0){
		if(x / i % i == 0) return mp[x] = 0;
		else c *= -1;
	}
	return mp[x] = c;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for(int i = 0; i < n; i ++) cin >> a[i];
		int ans = 1;
		{
			fac.clear();
			int x = a[0];
			for(int i = 2; i * i <= x; i ++) if(x % i == 0) {
				while(x % i == 0) x /= i;
				fac.emplace_back(i);
			}
			if(x != 1) fac.emplace_back(x);
		}
		for(int i = 1; i < n; i ++) {
			if(a[i - 1] % a[i] != 0) {
				ans = 0;
				break;
			}
			int x = a[i - 1] / a[i], lim = m / a[i], res = 0;
			for(int i = 1; i * i <= x; i ++) if(x % i == 0) {
				res += mu(i) * (lim / i);
				if(i * i != x) res += mu(x / i) * (lim / (x / i));
			}
			ans = 1ll * ans * res % mod;
		}
		cout << ans << '\n';
		// break;
	}
	return 0;
}
