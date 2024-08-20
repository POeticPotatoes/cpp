#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<long long, int> count;

    int x, y;
    for (int i=1; ++i<27;){
        cout << "? 1 " << i << endl;
        cin >> x;
        if (x == -1) {
            cout << i-1 << endl;
            return 0;
        }
        cout << "? " << i << " 1" << endl;
        cin >> y;
    }
}
