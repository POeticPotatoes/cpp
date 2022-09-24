#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, h, cur = 0;
        cin >> n;
        bool b = false;
        while (n--) {
            cin >> h;
            if (h <= cur) {
                b = true;
            }
            cur = h;
        }
        if (b)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}
