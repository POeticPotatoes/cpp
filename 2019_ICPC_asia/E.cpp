#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;
 
void solve(){
    long long k, l;
    cin >> k >> l;
    if (l > 2000) {
        cout << -1 << "\n";
        return;
    }

    if (k < 1000000) {
        cout << k+2 << " -" << k+1;
        for (int i=2;i<l;i++)
            cout << " " << -100;
        cout << "\n";
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
