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

int n;
string s;
void print(int tp) {
	if (tp == 0) cout << "ACCESS DENIED\n";
	else if (tp == 1) cout << "OK\n";
	else cout << "OK IF ACCOMPANIED\n";
}
int main() {
	IO;
	cin >> n >> s;
	if (s == "G") print(1);
	else if (s == "PG") {
		if (n < 13) print(2);
		else print(1);
	}
	else if (s == "R-13") {
		if (n < 13) print(0);
		else print(1);
	}
	else if (s == "R-16") {
		if (n < 16) print(0);
		else print(1);
	}
	else {
		if (n < 18) print(0);
		else print(1);
	}
	return 0;
}
