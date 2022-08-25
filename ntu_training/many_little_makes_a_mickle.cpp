#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int sums[100];

int main() {
    
    int t;
    cin >> t;

    sums[0] = 1;
    for (int i=2; i<=100; i++) {
        sums[i-1] = sums[i-2] + (i)*(i);
    }

    while (t--) {
        int n, m;
        cin >> n >> m;

        cout << sums[n-1] * m << endl;
    }
}
