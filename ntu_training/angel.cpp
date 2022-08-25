#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {

    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }

    if (n < 4) {
        cout << 2 << endl << "2 2" << endl;
        return 0;
    }

    cout << n << endl;
    cout << 1;
    for (int i=2;i<=n;i++)
        cout << " " << i;
    cout << endl;
}
