#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    int n, s, a, counter=0;
    cin >> n >> s;
    if (s%2) {
        cout << "yes" << endl;
        return 0;
    }

    s /= 2;
    while (n--) {
        cin >> a;
        if (s!=a) continue;
        counter++;
        if (counter > 2) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
}
