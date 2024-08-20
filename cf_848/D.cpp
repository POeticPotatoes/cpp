#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define ll long long

const long long M = 998244353;

ll modPow(ll v, ll p) {
    if (!p) return 1;
    ll ans = modPow(v, p/2);
    ans = (ans*ans)%M;
    if (p&1) ans = (ans*v)%M;
    return ans;
}

ll inv(ll v) { return modPow(v, M-2); }

void solve() {
    ll n;
    cin>>n;
    string A, B;
    cin>>A>>B;

    ll d=0;
    for (int i=0;i<n;i++) d+=A[i]!=B[i];
    deb(d, n);
    vector<ll> DP(n+1);
    DP[n] = 1;
    for (ll i=n-1;i>=1;i--) {
        ll v = inv(i);
        DP[i] = ((n*v)%M + (((n-i+M)%M *v)%M * DP[i+1]))%M;
    }
    deb(DP);

    ll ans = 0;
    for (int i=1;i<=d;i++)
        ans = (ans+DP[i]) %M;
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
