#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        if (n%2)
            cout << 0 << endl;
        else if (n%4)
            cout << (n/4-1)*n + n/4 << endl;
        else
            cout << n/4 * n << endl;
    }
}
