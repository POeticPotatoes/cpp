#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;
#define MAX 12582912

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string moves;
    int cur = MAX, l;
    cin >> moves;
    l = moves.size();
    pair<int,int> pos{0,0};
    vector<pair<int,int>> blocks;

    if (moves.size()>2 && (
                (moves[l-1] == 'L' && moves[l-2] == 'R' && moves[l-3] == 'L')
                || (moves[l-1] == 'R' && moves[l-2] == 'L' && moves[l-3] == 'R')
                || (moves[l-1] == 'U' && moves[l-2] == 'D' && moves[l-3] == 'U')
                || (moves[l-1] == 'D' && moves[l-2] == 'U' && moves[l-3] == 'D')
                )) {
        cout << "impossible" << endl;
        return 0;
    }

    for (int i=l-1;i>=0;i--) {
        switch (moves[i]) {
        case 'L':
            if (moves[i+1] == 'R') continue;
            blocks.emplace_back(pair<int, int>{pos.first-1, pos.second});
            pos.first += cur;
            break;
        case 'R':
            if (moves[i+1] == 'L') continue;
            blocks.emplace_back(pair<int, int>{pos.first+1, pos.second});
            pos.first -= cur;
            break;
        case 'U':
            if (moves[i+1] == 'D') continue;
            blocks.emplace_back(pair<int, int>{pos.first, pos.second+1});
            pos.second -= cur;
            break;
        case 'D':
            if (moves[i+1] == 'U') continue;
            blocks.emplace_back(pair<int, int>{pos.first, pos.second-1});
            pos.second += cur;
            break;
        }
        cur >>= 1;
    }

    cout << pos.first << " " << pos.second << endl << blocks.size() << endl;

    for (auto b: blocks) cout << b.first << " " << b.second << endl;
}
