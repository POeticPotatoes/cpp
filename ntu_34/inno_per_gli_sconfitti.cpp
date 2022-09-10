#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int schools[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m=0, x, y, z;
    cin >> n;
    
    for (int i=0;i<n;i++) {
        cin >> schools[i];
    }

    cin >> x >> y >> z;
    x--;
    y--;
    z--;

    for (int i=0;i<n;i++) {
        if (i == x || i == y || i == z)
            continue;
        m = max(m, schools[i]);
    }

    m++;

    cout << max(0, m-schools[x]) + max(0, m-schools[y]) + max(0, m-schools[z]) << endl;
}
