#include <bits/stdc++.h>
using namespace std;

bitset<200000> blue;

int main() {
    int t, n, m, a, b;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        while (m--) {
            cin >> a >> b;
            bool result = !(blue[a]^blue[b]);
            cout << result;
            blue[a] = blue[a] || result;
            blue[b] = blue[b] || result;
        }
        blue = bitset<200000>();
        cout << endl;
    }
}
