#include <bits/stdc++.h>
#define ll long long
using namespace std;

constexpr long long m = 1000000001;

ll n, k, p, s, cur;
bool flag;

void solve() {
        cin >> n >> k;

        cin>>cur;
        s=cur, p = n==k?cur:ceil(cur/(n-k+1.0));
        
        flag = 0;
        for (int i=1;i<k;i++) {
            cin>>cur;
            cur-=s;
            if (cur<p) {
                flag = 1;
                continue;
            }
            p = cur;
            s += p;
        }
        cout<<(flag?"NO":"YES") <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
