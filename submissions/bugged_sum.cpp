#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, a;
    bool touched=false;
    cin >> n >> s;
    if (s%2) {
        cout << "yes" << endl;
        return 0;
    }

    s /= 2;
    while (n--) {
        cin >> a;
        if (s!=a) continue;
        if (touched) {
            cout << "no" << endl;
            return 0;
        }
        touched = true;
    }

    cout << "yes" << endl;
}
