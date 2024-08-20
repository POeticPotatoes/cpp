#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m, n;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        if (m < n || (m%2&&!(n%2))) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;

        int end = (n-1)/2*2;
        for (int i=0; i<end; i++) {
            cout << "1 ";
            m--;
        }

        if (n%2) {
            cout << m << endl;
            continue;
        }
        cout << m/2 << " " << m/2 << endl;
    }
}
