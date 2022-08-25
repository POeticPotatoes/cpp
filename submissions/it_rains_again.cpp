#include <bits/stdc++.h>
using namespace std;

bitset<100000> plane;

int main() {
    int n, x1, y1, x2, y2;
    cin >> n;

    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i=x1; i<x2; i++) {
            if(!plane[i])
                plane[i] = true;
        }
    }

    cout << plane.count() << endl;
}
