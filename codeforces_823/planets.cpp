#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, c, i, tot=0, p[101]{};
        cin >> n >> c;

        while (n--) {
            cin >> i;
            p[i]+=1;
        }

        for (auto a: p) {
            tot += min(a, c);
        }
        cout << tot << endl;
    }
}
