#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
typedef long long ll;

const int N = 6000;

ll n, M, fac[N]{1}, inv[N];

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans)%M;
    if (p&1) ans = (ans*v)%M;
    return ans;
}

ll choose(ll a, ll b) { 
    // deb(a, b);
    return ((fac[a]*inv[b])%M * inv[a-b])%M; 
}

void solve() {
    cin>>n>>M;
    ll u = (n-1)/2;
    for (int i=1;i<=n;i++) {
        fac[i] = (fac[i-1] * i) %M;
    }
    inv[n] = modPow(fac[n], M-2);
    for (int i=n;i>=1;i--) inv[i-1] = (inv[i]*i) %M;

    ll x = choose(4, 2);
    deb(x);

    ll ans=0, c, d, e;
    for (int i=1;i<=u;i++) {
        c = i+!(n&1);
        d = 0;
        for (int j=0;j<=i-1;j++) {
            e = fac[j+n-2-i];
            e = (e*choose(i-1, j)) %M;
            d = (d+e) %M;
            // deb(i, j, j+n-2-i, i-1, j, e, d);
        }
        c = (c*d) %M;
        // deb(i, i+!(n&1), (fac[n-2-i]), d, c);
        ans = (ans + c) %M;
    }
    ans = (ans*n)%M;
    if (!(n&1)) {
        c = (n * fac[n-2]) %M;
        ans = (ans+c)%M;
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
