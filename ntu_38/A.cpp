#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        double c,m=100,e;
        for (int i=0;i<6;i++) {
            cin >> c;
            m = min(m, c);
        }
        cin >> e;
        if (e<=m) cout << "DATA IS BIAS!" << endl;
        else cout << ceil(100*(e-m)/m) << "% INCREASE!" << endl;
    }
}
