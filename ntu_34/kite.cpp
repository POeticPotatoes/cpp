#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        if (n < 4 || n%2)
            cout << 0 << endl;
        else if (n%4)
            cout << (n/2) * (n/2-1) << endl;
/*            cout << (n/4)*n << endl;*/
        else
            cout << (n/2) * (n/2-1) - n/4 << endl;
/*            cout << n/4 + (n/4 - 1)*n << endl;*/
    }
}
