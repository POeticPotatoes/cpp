#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {

        int n, x, y, l, curr;
        cin >> n >> x >> y;

        if ((x==0 && y==0)||(x&&y)) {
            cout << -1 << endl;
            continue;
        }
        l = max(x, y);

        if ((n-1)%l) {
            cout << -1 << endl;
            continue;
        }
        
        for (int i=1;i<n;i++) {
            curr = i+1;
            cout << curr << " ";
            while (i!=n && i%l) {
                cout << curr << " ";
                i++;
            }
        }
        cout << endl;
    }
}
