#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, l, x, y;
    cin >> w >> l >> x >> y;
    x = min(w-x+1, x);
    y = min(l-y+1, y);

    int t = x*y;
    if (t >= w*l/2) {
        cout << "I don't wanna do this anymore!" << endl;
        return 0;
    }
    cout << t << endl;
}
