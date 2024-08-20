#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> ans;

    ll a = (n*n + 5*n -2)/(2*n),
       excess = (n*n+5*n-2-2*a*n)/2,
       top = a+n-2;
    ans.emplace_back(a);
    ans.emplace_back(1+n+a);

    for (int i=2;i<n;i++,top--, excess-=2) {
        ll add=top;
        if (excess>0)
            add += min(2ll, excess);
        ans.emplace_back(add);
    }
    
    cout<<ans[0];
    for (int i=1;i<n;i++)
        cout<<" "<<ans[i];
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
