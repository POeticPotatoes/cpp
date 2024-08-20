#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif

#define ll long long

const ll N = 2e5;

void solve() {
    ll n, k;
    string A, B;
    cin>>n>>k>>A>>B;

    ll S[26];

    ll s=0;
    memset(S, 0xff, sizeof(S));
    for (ll i=0;i<n;i++)
        if (S[A[i]-'a'] < 0)
            S[A[i]-'a'] = s++;

    if (k>=s) return (void) (cout<<n*(n-1)/2 + n<<endl);
    ll ans=0, m=1<<s, c, l;
    for (ll p=0;p<m;p++) {
        if (__builtin_popcount(p) != k) continue;
        l = 0, c = 0;
        for (ll i=0;i<n;i++) {
            // If the char is correct/ swapped, continue
            if (A[i] == B[i] || ((p>>S[A[i]-'a'])&1)) continue;
            c += (i-l)*(i-l-1)/2 + (i-l);
            l = i+1;
        }
        c += (n-l)*(n-l-1)/2 + (n-l);
        ans = max(ans, c);
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
