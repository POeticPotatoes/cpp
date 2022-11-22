#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, c=0;
        string s;
        cin >> n >> s;
        for (int i=n;--i;) {
            c += s[i]=='A'?1:-1;
            if (c<0) break;
        }
        cout << (c<1?"No":"Yes") << endl;
    }
}
