#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

void solve() {
    int l, r, x, a, b,lower,higher;
    cin >> l >> r >> x>>a>>b;

    if (a==b) {
        cout <<0<<endl;
        return;
    }
    lower = min(a,b);
    higher = max(a,b);
    if (higher-lower>=x) {
        cout<<1<<endl;
        return;
    }
    if (r-higher>=x||lower-l>=x) {
        cout << 2<<endl;
        return;
    }
    if (r-lower>=x && higher-l>=x) {
        cout<<3<<endl;
        return;
    }
    cout<<-1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
