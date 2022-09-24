#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x,y,z, a;
        cin >> x >> y >> z;
        y += x;
        a = z%y;
        cout << (z/y)*x*3 + min(x*3, a*3) << endl;
    }
}
