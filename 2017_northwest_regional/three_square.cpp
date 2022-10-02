#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int panes[3][2], a,b,w=0,t=0;
    bool same = true;

    for (int i=0;i<3;i++) {
        cin >> a >> b;
        panes[i][0] = max(a, b);
        panes[i][1] = min(a, b);

        same = panes[w][0] == panes[i][0] && same;

        if (panes[w][0] < panes[i][0]) w = i;
    }

    if (same) {
        t += panes[w][1];
        for (int i=0; i<3; i++) {
            if (i==w) continue;
            t+=panes[i][1];
        }
    }
    else
        for (int i=0; i<3; i++) {
            if (i==w) continue;
            if (panes[i][0] + panes[w][1] == panes[w][0])
                t += panes[i][1];
            else if (panes[i][1] + panes[w][1] == panes[w][0])
                t += panes[i][0];
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    cout << (t == panes[w][0]?"YES":"NO") << endl;
    return 0;
}
