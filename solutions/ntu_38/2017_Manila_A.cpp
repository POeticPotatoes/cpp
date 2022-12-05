#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 510000;
const int M = 5100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n;

void solve(){
    int m = 1e7, num, a;
    for (int i = 0; i <= 5; i ++) {
        cin >> num;
        m = min(m, num);
    }
    cin >> a;
    if (m >= a) cout << "DATA IS BIAS!\n";
    else {
        cout << ceil(100 * (double)(a - m) / m ) << "% INCREASE!\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}