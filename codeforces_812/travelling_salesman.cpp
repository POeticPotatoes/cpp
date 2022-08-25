#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, l=0, r=0, u=0, d=0;
        cin >> n;

        while (n--) {
            int x, y;
            cin >> x >> y;

            if (x < l)
                l = x;
            if (x > r)
                r = x;
            if (y < d)
                d = y;
            if (y > u)
                u = y;
        }

        cout << (r + u - l - d)*2 << endl;
    }
}
