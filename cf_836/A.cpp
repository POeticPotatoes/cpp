#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int l = s.size();
    for (int i=l;i--;)
        s += s[i];
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
