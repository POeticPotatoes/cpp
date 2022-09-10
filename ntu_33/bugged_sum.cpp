#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, a;
    bool visited = false;
    cin >> n >> s;
    if (s%2) {
        cout << "yes" << endl;
        return 0;
    }

    s /= 2;
    while (n--) {
        cin >> a;
        if (s!=a) continue;
        cout << "owo" << visited <<  endl;
        if (visited) {
            cout << "no\n";
            return 0;
        visited = true;
        }
    }

    cout << "yes" << endl;
}
