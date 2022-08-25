#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int fraction[100];
int a, b, t;

int main() {
    cin >> t;

    while (t--) {
        cin >> a >> b;
        
        int count = -1;
        bool flip = false;
        while (true) {
            count++;
            if (flip) {
                if (b==1 && !a) {
                    count --;
                    break;
                }
                fraction[count] = b/a;
                b = b-fraction[count]*a;
                flip = false;
                continue;
            }
            if (a==1 && !b) {
                count --;
                break;
            }
            fraction[count] = a/b;
            a = a-fraction[count]*b;
            flip = true;
        }

        cout << count;
        for (int i=0; i <= count;i++) {
            cout  << " " << fraction[i];
        }
        cout << endl;
    }
}
