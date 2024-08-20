#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    if (n%x) {
        cout << -1 << endl;
        return;
    }

    cout<<x;
    for (int i=2;i<n;i++) {
        if (i!=x) {
            cout<<" "<<i;
            continue;
        }
        int next = x*2;
        for (;n%next;next+=x);
        cout<<" "<<next;
        x = next;
    }
    cout<<" 1"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
