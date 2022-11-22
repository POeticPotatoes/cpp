#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    
    bool state=1, proper=true;
    int cur = 0;
    stack<int> o;

    for (auto c: s) {
        if (c == ' ') continue;
        
        switch (c) {
            case '+': case '-': case '*': case '/': case '%':
                if (state) {
                    cout << "error" << endl;
                    return 0;
                }
                cur++;
                state = 1;
                break;
            case ')':
                if (state || o.empty()) {
                    cout << "error" << endl;
                    return 0;
                }
                if (cur != 1) proper = false;
                cur = o.top();
                o.pop();
                break;
            case '(':
                if (!state) {
                    cout << "error" << endl;
                    return 0;
                }

                o.push(cur);
                cur = 0;
                break;
            default:
                if (!state) {
                    cout << "error" << endl;
                    return 0;
                }
                state = 0;
        }
    }
    if (o.size()||state) {
        cout << "error" << endl;
        return 0;
    }
    cout << (cur==1&&proper?"proper":"improper") << endl;
}
