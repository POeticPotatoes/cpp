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

const int N = 110;
const int M = 1100000;
const int mod = 999983;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int T, n, k, l, deg, p;
// s: sorted sequence
LL s[N], t[N], dp[2][N];
LL f(LL x) {
    LL res = 0, cur = 1;
    repn(i, 0, deg) {
        res = (res + cur * dp[p][i]) % mod;
        cur = cur * x % mod;
    }
    return res;
}
int main() {
    IO;
    cin >> T;
    while (T--) {
        cin >> n >> k >> l;
        repn(i, 1, l) cin >> s[i], s[i] = (s[i] + mod) % mod;
        sort(s + 1, s + l + 1);
        t[deg = 1] = s[1];
        repn(i, 2, l) if (s[i] != s[i - 1]) t[++deg] = s[i];
        if (deg > k) {
            cout << "0\n";
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        p = 0;
        repn(i, 1, deg) {
            memset(dp[p ^ 1], 0, sizeof(dp[p ^ 1]));
            rep(j, 0, i) dp[p ^ 1][j + 1] = dp[p][j];
            rep(j, 0, i) dp[p ^ 1][j] = (dp[p ^ 1][j] - (dp[p][j] * t[i] % mod) + mod) % mod;
            p ^= 1;
        }
        repn(i, 1, deg) assert(f(t[i]) == 0);
        cout << n << "\n";
        repn(i, 1, n) {
            cout << deg;
            pern(j, 0, deg) {
                cout << " " << (dp[p][j] * i % mod);
            }
            cout << "\n";
        }
    }
    return 0;
}
