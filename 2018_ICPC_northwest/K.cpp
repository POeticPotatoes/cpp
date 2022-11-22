#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c;
    cin >> n >> m;
    string pt, orig;
    vector<int> ans(m);
    cin >> orig >> pt;
    c = orig.size();

    for (int i=1;i<=c;i++) ans[m-i] = orig[c-i]-97;

    for (int a=m; a>c; a-=c) {
        for (int i=1;i<=c;i++) {
            if (a-i-c < 0) break;
            ans[a-i-c] = (pt[a-i] - ans[a-i]-71)%26;
        }
    }

    for (auto j:ans) cout << (char) (j+97);
    cout << endl;
}
