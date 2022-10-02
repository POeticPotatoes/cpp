#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    unordered_map<char, int> nums;
    for (int i=97;i<123;i++) nums[i] = 0;
    
    for (auto c: s) {
        int m=0;
        for (int i=97;i<c;i++) {
            m = max(m, nums[i]);
        }
        m++;
        nums[c] = m;
    }

    int m=0;
    for (int i=97;i<123;i++) {
        m = max(m, nums[i]);
    }
    cout << 26-m << endl;
}
