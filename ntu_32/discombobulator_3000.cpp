#include <bits/stdc++.h>
using namespace std;

# define forn(i, x, n) for (int i = int(x); i < int(n); i++)

int main() {
    
    int n, maxPos=0;
    cin >> n;

    int curr, x;
    cout << "? 0 0" << endl;
    cin >> curr;

    bool peaked = true;

    forn(i, 1, n) {
        cout << "? 0 " << i << endl;
        cin >> x;

        if (x == n) {
            maxPos = i;
            continue;
        }
        peaked = false;
    }

    if (peaked) {
        forn(i, 0, n) {
            cout << "? 1 " << i << endl;
            cin >> x;
            
            if (x == n) {
                cout << "! " << i << endl;
                break;
            }
        }
        return 0;
    }
    int a = (maxPos+1)%n;
    forn(i, 1, n) {
        cout << "? " << i << " " << a << endl;
        cin >> x;
        
        if (x == n) {
            cout << "! " << ((maxPos + n) - i)%n << endl;
            break;
        }
    }
    return 0;
}
