#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (((n+1)*n)^(n+1)) << endl;
    }
}
