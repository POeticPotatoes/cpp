#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, x, y;
    cin >> n >> a >> b;
    vector<int> e(n+1);
    vector<bool> v(n+1);

    while (b--) {
        cin >> x >> y;
        e[x] = y;
    }

    deque<int> q;
    q.push_back(1);

    while (q.size()) {
        int i = q.back();
        if (i == a) {
            cout << "YES" << endl;
            return 0;
        }
        q.pop_back();
        v[i] = true;

        if (e[i]) {
            q.push_back(e[i]);
            continue;
        }
        if (i>1 && (!v[i-1]))
            q.push_back(i-1);
        if (i<n && (!v[i+1]))
            q.push_back(i+1);
    }
    cout << "NO" << endl;
}
