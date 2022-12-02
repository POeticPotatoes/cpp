#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll process(ll n) {
    ll a;
    for (;(a=n%10)!=2;n+=a)
        if (a==0) return n;
    return n;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for (ll i=0;i<n;i++) cin >> nums[i];
    ll i = process(nums[0]);
    bool eq = !(i%10);
    for (ll j=1;j<n;j++) {
        ll x = process(nums[j]);
        if (eq && x!=i) {
            cout <<"NO"<<endl;
            return;
        }
        else if ((i-x)%20) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
