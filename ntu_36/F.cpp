#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int dfs(vector<vector<vector<pair<int, int>>>> &g, vector<vector<int>> &visited, int y, int x) {
    visited[y][x] = -2;
    int s = 10000000;
    for (auto i: g[y][x]) {
        if (visited[i.first][i.second] == -1) {
            visited[y][x] = 1;
            return 1;
        }
        if (visited[i.first][i.second]) {
            if (visited[i.first][i.second] > 0) s = min(s, 1+visited[i.first][i.second]);
            continue;
        }
        int res = 1+dfs(g, visited, i.first, i.second);
        s = min(res, s);
    }
    visited[y][x] = s;
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int _;
    cin >> _;
    while (_--) {
        int r, c;
        cin >> r >> c;
        vector<vector<vector<pair<int, int>>>> g(r, vector<vector<pair<int, int>>>(c));
        vector<vector<int>> visited(r, vector<int>(c));
        pair<int, int> start;
        string cur;

        int h = 4*r + 4;
        vector<string> raw(h);
        for (int i=0;i<h;i++) getline(cin, raw[i]);
        int p, o;
        for (int y=0;y<r*2;y++) {
            p = 4 + (y&1)*6;
            o = 3 + 2*y;
            for (int x=y&1;x<c;x+=2) {
                if (raw[o][p] == 'S') start = {y/2, x};
                if (raw[o][p] == 'T') visited[y/2][x] = -1;
                if (raw[o-1][p-3] == ' ')
                    g[y/2][x].emplace_back(pair<int, int>{(y-1)/2, x-1});
                if (raw[o-1][p+3] == ' ')
                    g[y/2][x].emplace_back(pair<int, int>{(y-1)/2, x+1});
                if (raw[o+1][p-3] == ' ')
                    g[y/2][x].emplace_back(pair<int, int>{(y+1)/2, x-1});
                if (raw[o+1][p+3] == ' ')
                    g[y/2][x].emplace_back(pair<int, int>{(y+1)/2, x+1});
                if (raw[o-2][p] == ' ')
                    g[y/2][x].emplace_back(pair<int,int>{(y-2)/2, x});
                if (raw[o+2][p] == ' ')
                    g[y/2][x].emplace_back(pair<int,int>{(y+2)/2, x});
                p += 12;
            }
        }
        /*
        for (int y=0;y<r;y++)
            for (int x=0;x<c;x++) {
                cout << "List for cell " << y << ", " << x << endl;
                for (auto i: g[y][x]) cout << " (" << i.first << ", " << i.second << ")";
                cout << endl;
            }
            */
        cout << 1+dfs(g, visited, start.first, start.second) << endl;
    }

}
