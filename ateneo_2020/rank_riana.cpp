#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int count=0, m=0, cur=0;

    for (auto c: s) {
        if (c == '.') {
            count++;
            cur++;
            continue;
        }
        if (cur) {
            m = max(cur, m);
            cur = 0;
        }
    }
    m = max(cur, m);

    cout << count-m << endl;
}
