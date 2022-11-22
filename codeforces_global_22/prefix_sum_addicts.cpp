#include <bits/stdc++.h>
using namespace std;

constexpr long long m = 1000000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, cur, prev, diff, end, start = m;
        cin >> n >> k;
        
        cin >> end;
        prev = end;
        if (k > 1) {
            cin >> prev;
            start = prev-end;
            diff = start;
        }
        bool done = false;
        for (int i=2;i<k;i++) {
            cin >> cur;
            if (diff > cur - prev) {
                done = true;
                cout << "No" << endl;
            }
            diff = cur-prev;
            prev = cur;
        }
        if (done) continue;
        if ((end+n-k)/(n-k+1) > start)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}
