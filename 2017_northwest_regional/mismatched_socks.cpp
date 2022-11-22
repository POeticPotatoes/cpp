#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t=0, m=0, c;
    cin >> n;
    while (n--) {
        cin >> c;
        m = max(c, m);
        t += c;
    }

    if (m > t/2)
        cout << t-m << endl;
    else
        cout << t/2 << endl;
}
