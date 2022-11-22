#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        switch (s[s.size()-1]) {
            case 'a':
                cout << s + "s" << endl;
                break;
            case 'i': case 'y':
                s[s.size()-1] = 'i';
                cout << s + "os" << endl;
                break;
            case 'r':
            case 'v':
            case 'l':
                cout << s + "es" << endl;
                break;
            case 't':
            case 'w':
                cout << s + "as" << endl;
                break;
            case 'u':
            case 'o':
                cout << s + "s" << endl;
                break;
            case 'n':
                s[s.size()-1] = 'a';
                cout << s + "nes" << endl;
                break;
            case 'e':
                if (s[s.size()-2] == 'n') {
                    s = s.substr(0,s.size()-2);
                    cout << s + "anes" << endl;
                    break;
                }
            default:
                cout << s + "us" << endl;
        }
    }
}
