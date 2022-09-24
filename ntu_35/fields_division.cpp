#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> p(n+1);
    vector<bool> farms(n);
    for (int i=0;i<m;i++) {
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    deque<int> q;
    q.push_back(n-1);
    farms[n-1] = true;

    while (q.size()) {
        int i = q.front();
        q.pop_front();

        for (auto e: p[i]) {
            if (e == n || farms[e]) continue;
            farms[e] = true;
            q.push_back(e);
        }
    }
    for (int i=1;i<=n;i++) {
        if (farms[i])
            cout << "B";
        else
            cout << "A";
    }
    cout << endl;
}
