#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,i,j;
    cin >> t;
    while (t--) {
        cin >> n;
        for (i=n, j=(n+1)/2;j>0;i--,j--) {
            cout << j << " ";
            if (j != 1) cout << i << " ";
        }
        if (!(n&1)) cout << i+1;
        cout << endl;
    }
}
