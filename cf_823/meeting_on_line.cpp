#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {

        int n, l;
        float s=0;
        cin >> n;
        vector<int> p(n);
        vector<pair<int, int>> c(n);
        for (int i=0;i<n;i++) cin >> p[i];
        for (int i=0;i<n;i++) {
            cin >> l;
            s += l;
            c[i] = {p[i], l};
        }
        if (n==1) {
            cout << c[0].first << endl;
            continue;
        }

        float i=1;
        sort(c.begin(), c.end());
        int m = c[0].first + c[0].second;
        s -= c[0].first;
        s += c[c.size()-1].first;
        s /= 2.0;
        s += c[0].first;
        for (;i<n;i++) {
            m += (c[i].first-c[i-1].first)*i;
            m += c[i].second;
            if (m >= s) break;
        }
        // cout << "m: " << m << " s: " << s << " i: " << i << endl;
        cout << c[i].first - ((m-s)/i)*(!!(c[i].first-c[i-1].first)) << endl;
    }
}
