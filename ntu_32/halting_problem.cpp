#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    if (k != 2) {
        int a, b;
        while (m--) {
            cin >> a >> b;
        }
        int ans = k==1?n:1;
        cout << ans << endl;;
        return 0;
    }

    vector<bool*> proximity(n);
    for (int i=0; i<n; i++) {
        proximity[i] = new bool[n]{false};
    }

    while (m--) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;

        proximity[n1][n2] = true;
        proximity[n2][n1] = true;
    }

    bool* colors = new bool[n]{0};
    bool* visited = new bool[n]{0};
    colors[0] = 1;
    visited[0] = 1;
    deque<int> queue;
    queue.emplace_back(0);
    int counter = 0;

    while (queue.size() > 0) {
        int r = queue.front();
        queue.pop_front();
        bool color = colors[r];
        counter += color;
        
        for (int i=0; i<n; i++) {
            if (!proximity[r][i])
                continue;

            if (!visited[i]) {
                queue.emplace_back(i);
                colors[i] = !color;
                visited[i] = true;
                continue;
            }

            if (color != colors[i]) continue;

            cout << 1 << endl;
            delete[] colors;
            delete[] visited;
            for (auto node: proximity)
                delete[] node;
            return 0;
        }
    }

    cout << max(n-counter, counter) << endl;

    delete[] colors;
    delete[] visited;
    for (auto node: proximity)
        delete[] node;
}
