#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n,m,fives=0,twos=0,x=1;

    cin>>n>>m;
    ll ans = n;

    for (;!(n&1);n>>=1,twos++);
    for (;!(n%5);n/=5,fives++);

    x *= pow(5, min(max(0ll,twos-fives), static_cast<ll>(floor(log(m)/log(5)))));
    x *= pow(2, min(max(0ll,fives-twos), static_cast<ll>(floor(log(m)/log(2)))));
    if (x>m) {
        cout <<ans*m << endl;
        return;
    }
    for (;x<=m;x*=10);
    x/=10;
    cout << ans*(x*(m/x)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)solve();
}
