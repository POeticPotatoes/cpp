#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n==1) {
        cout << 1 << endl;
        return;
    }

    if (n&1) {
        for (int i=1;i<n;i++)
            cout<<"1 ";
        cout<<1<<endl;
        return;
    }

    for (int i=n-2;i;i--)
        cout<<"2 ";
    cout<<"3 1"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
