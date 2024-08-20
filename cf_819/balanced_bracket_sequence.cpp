#include <bits/stdc++.h>
using namespace std;

int main() {

    int t, n, ans;
    string s;
    char prev;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        
        ans = 0;
        prev = '(';
        for (auto c: s) {
            if (c == '(')
                ans+= prev == '(';
            prev = c;
        }

        cout << ans << endl;
    }
}
