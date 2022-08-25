#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long i, a, d = 0;
        cin >> i;

        a = i;

        while (a != 0) {
            d += a%10;
            a /= 10;
        }

        cout << i * d << endl;
    }
}
