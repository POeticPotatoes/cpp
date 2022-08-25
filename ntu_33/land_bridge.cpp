#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

bitset<500> board[500];
int *visited[500];
deque<pair<int, int>> q;
int n;

void check(int y,int x,int cost) {
    if (x<0||x>=n||y<0||y>=n) return;
    int c = cost + board[y][x];

    /* cout << " y:" << y << " x:" << x << " cost:" << cost << " c:" << c << endl; */

    if (visited[y][x] > c) {
        q.emplace_back(pair<int, int>{y, x});
        visited[y][x] = cost + board[y][x];
    }
}

void printBoard() {
    cout << "----------------" << endl;
    for (int y=0;y<n;y++) {
        for (int x=0;x<n;x++)
            cout << " " << board[y][x];
        cout << endl;
    }
    cout << "----------------" << endl;
}

void printVisited() {
    cout << "----------------" << endl;
    for (int y=0;y<n;y++) {
        for (int x=0;x<n;x++)
            cout << " " << visited[y][x];
        cout << endl;
    }
    cout << "----------------" << endl;
}

int main() {
    cin >> n;

    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        for (int c=0;c<n;c++) {
            board[i][c] = s[c] != '1';
        }
        int* row = new int[500];
        fill_n(row, 500, 600);
        visited[i] = row;
    }
    visited[n-1][n-1] = 0;

    q.emplace_back(pair<int, int>{n-1, n-1});

    while (q.size()) {
        pair<int, int> coords = q.front();
        q.pop_front();
        int cost = visited[coords.first][coords.second];

        check(coords.first + 1, coords.second, cost);
        check(coords.first - 1, coords.second, cost);
        check(coords.first, coords.second + 1, cost);
        check(coords.first, coords.second - 1, cost);
    }

    cout << visited[0][0] << endl;
}
