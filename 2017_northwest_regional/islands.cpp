#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

vector<string> planet;
vector<vector<bool>> visited;
int n, m, c=0;

void check(int x, int y) {
    if (y<0 || y==n || x<0 || x==m || planet[y][x] == 'W' || visited[y][x]) return;
    visited[y][x] = true;
    check(x+1, y);
    check(x, y+1);
    check(x-1, y);
    check(x, y-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    planet = vector<string>(n);
    for (int i=0;i<n;i++) cin >> planet[i];
    visited = vector<vector<bool>>(n);
    for (auto &v: visited) v = vector<bool>(m);

    for (int y=0;y<n;y++) {
        for (int x=0;x<m;x++) {
            if (planet[y][x] != 'L' || visited[y][x])
                continue;
            check(x, y);
            c++;
        }
    }
    cout << c << endl;
}
