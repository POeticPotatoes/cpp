#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    while (a) {
        int temp = b%a;
        b=a;
        a=temp;
    }
    return b;
}

void solve() {
    ll n, m=0, cur, g=0;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> cur;
        g = gcd(g,cur);
        m = max(m, cur);
    }

    cout << m/g << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
