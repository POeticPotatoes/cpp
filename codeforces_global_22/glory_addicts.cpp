#include <bits/stdc++.h>
using namespace std;

vector<int> type(100000);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, c, as=0, bs=0, sum = 0;
        cin >> n;
        if (!n) {
            cout << 0 << endl;
            continue;
        }
        vector<long long> a, b, *x, *y;
        for (int i=0;i<n;i++) {
            cin >> type[i]; 
        }

        for (int i=0;i<n;i++) {
            cin >> c;
            if (type[i]) {
                b.emplace_back(c);
                bs += c;
            }
            else {
                a.emplace_back(c);
                as += c;
            }
        }
        if (n == 1) {
            cout << as + bs << endl;
            continue;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a.size() == b.size()) {
            sum = (as + bs - a[0] - b[0])*2;
            if (a[0] > b[0])
                cout << (sum + a[0]*2 + b[0]) << endl;
            else
                cout << (sum + b[0]*2 + a[0]) << endl;
            continue;
        }

        if (a.size() > b.size()) {
            y = &a;
            x = &b;
        } else {
            x = &a;
            y = &b;
        }
        long long s = y->size() - x->size();
        for (int i=0;i<s;i++) {
            sum += y->at(i);
        }
        cout << as*2 + bs*2 - sum << endl;
    }
}
