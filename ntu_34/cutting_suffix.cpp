#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    char l = s[s.size()-1];

    int size = s.size()-1;
    for (int i=0; i<size; i++) {
        char c = s[i];
        if (c != l) {
            cout << 0;
            return 0;
        }
    }
    cout << s.size()-1 << endl;
    return 0;
}
