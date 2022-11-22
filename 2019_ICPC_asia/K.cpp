#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long t, n, c, s;
    cin >> t;
    while (t--) {
        s = 0;
        priority_queue<long, vector<long>, greater<long>> q;

        cin >> n;
        while (n--) {
            cin >> c;
            q.push(c);
        }

        while (q.size() > 1) {
            c = q.top(); q.pop();
            c += q.top(); q.pop();
            s += c;
            q.push(c);
        }
        cout << s << endl;
    }
}
