#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, a[101], c;
    cin >> t;
    while (t--) {
        bool valid = true;
        cin >> n >> a[0];
        for (int i=1;i<n;i++) {
            cin >> c;
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
            break;
        }
        if (!valid) continue;
        cout << a[0];
        for (int i=1;i<n;i++)
            cout << " " << a[i];
        cout << endl;
    }
}
