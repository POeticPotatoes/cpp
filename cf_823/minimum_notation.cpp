#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int buckets[10]{}, c=0;
        string s, a;
        cin >> s;

        for (auto i: s)
            buckets[min(i-47, 9)]++;

        for (int i=0; i<10;i++) {
            while (s[c]-'0' == i) {
                a += '0' + i;
                buckets[min(i+1,9)]--;
                c++;
            }
            while (buckets[i]) {
                if (s[c]-47 == i) {
                    a += s[c];
                    c++;
                    continue;
                }
                if (s[c]-'0' == i)
                    buckets[min(i+1,9)]--;
                else
                    buckets[i]--;
                a += '0' + i;
                c++;
            }
        }
        cout << a << endl;
    }
}
