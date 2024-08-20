#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, start;
        cin >> n;

        cin >> start;
        int i, end=start, low=1000, high=0, diff=0;
        while (--n) {
            cin >> i;
            diff = max(i-end, diff);
            end = i;
            low = min(end, low);
            high = max(high, end);
        }

        cout << max({diff, end-start, start-end, end-low, high-start}) << endl;
    }
}
