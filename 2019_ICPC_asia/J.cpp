#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int bfs(bitset<500> *cur, bitset<500> *visited, vector<bitset<500>> *tests, vector<int> *values, int n, int m) {
    if (cur->count() == n) return 0;
    auto pos = &(*values)[visited->to_ulong()];
    if (*pos) return *pos;
    int k = 16;
    for (int i=0;i<m;i++) {
        if ((*visited)[i]) continue;
        (*visited)[i] = 1;
        bitset<500> next = (*cur) | (*tests)[i];
        k = min(k, 1+bfs(&next, visited, tests, values, n, m));
        (*visited)[i] = 0;
    }
    *pos = k;
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<bitset<500>> tests(m);
        for (int i=0;i<m;i++) {
            cin >> s;
            tests[i] = bitset<500>(s);
        }

        bitset<500> check;
        for (int i=0;i<m;i++) check |= tests[i];
        if (check.count() != n) {
            cout << -1 << endl;
            continue;
        }

        int c=0, l, k;
        bitset<500> cur;
        bitset<500> visited;
        vector<int> values(32768);
        for (int i=0;i<n;i++) {
            if (cur[i]) continue;
            k = 0;
            for (int j=0;j<m;j++) {
                if (tests[j][i]) {
                    k++;
                    l=j;
                }
            }
            if (k == 1) {
                cur |= tests[l];
                visited[l] = 1;
                c++;
            }
        }
        c += bfs(&cur, &visited, &tests, &values, n, m);
        cout << c << endl;
    }
}
