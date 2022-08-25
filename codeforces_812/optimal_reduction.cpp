#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, high, curr, prev;
        cin >> n;

        cin >> prev;
        if (n == 1) {
            cout << "YES" << endl;
            continue;
        }

        bool dipped = false;
        high = prev;

        while (n-- > 1) {
            
            cin >> curr;
            if (dipped) continue;
            if (prev < curr) {
                if (high != prev) {
                    dipped = true;
                    continue;
                }
                high = curr;
            }
            prev = curr;
        }
        if (dipped)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
