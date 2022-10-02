#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t=0, n, k, c, a=0;
    priority_queue<long long, vector<long long>, greater<long long>> q;

    cin >> n >> k;

    for (int i=0;i<k;i++) {
        cin >> c;
        q.push(c);
    }

    for (int i=k;i<n;i++) {
        c = q.top();
        q.pop();
        t += c;
        a += t;
        cin >> c;
        q.push(c);
    }

    while (q.size()) {
        c = q.top();
        q.pop();
        t += c;
        a += t;
    }

    cout << a << endl;
}
