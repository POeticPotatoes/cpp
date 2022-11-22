#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

#define INC 0.06

int main() {
    int n,a,b,c;
    double l;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<pair<double,double>> coords(n);
    vector<double> angles(n);
    vector<bool> visited(n);

    while (--n) {
        cin >> a >> b;
        a--;
        b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    stack<int> q;
    q.push(0);
    visited[0] = true;
    while (q.size()) {
        c = q.top();
        q.pop();
        auto v = coords[c];
        l = angles[c];
        for (auto i: graph[c]) {
            if (visited[i]) continue;
            l += INC;
            q.push(i);
            coords[i] = {v.first+cos(l), v.second+sin(l)};
            angles[i] = l;
            visited[i] = true;
        }
    }
    for (auto i: coords)
        printf("%.7lf %.7lf\n", i.first, i.second);
}
