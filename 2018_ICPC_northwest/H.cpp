#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, b, a, i=1;
    cin >> n >> c >> b;
    vector<int> bits(n);
    
    while (b--) {
        cin >> a;
        bits[a-1] = 2;
    }

    if (c&1) {
        bits[0] = 1;
        c--;
        i++;
    }

    while (c) {
        if (bits[i] == 2) {
            i++;
            continue;
        }
        bits[i] = 1;
        c-=2;
        i+=2;
    }

    for (int j=0;j<n;j++)
        cout << bits[j]%2;
    cout << endl;
}
