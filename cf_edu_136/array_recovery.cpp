#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, a[101], c;
    cin>>n;
    cin>>a[0];
    bool valid = true;
    for (int i=1;i<n;i++) {
        cin >> c;
        if (!valid) continue;
        if (c==0) {
            a[i] = a[i-1];
            continue;
        }
        if (c > a[i-1]) {
            a[i] = c+a[i-1];
            continue;
        }
        cout << -1 << endl;
        valid = false;
    }
    if (!valid) return;
    cout << a[0];
    for (int i=1;i<n;i++)
        cout << " " << a[i];
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
