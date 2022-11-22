#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

struct car {
    bool isVertical;
    int l=0, x, y;
    car(int board[6][6], int a, int b, int id) {
        x = a;
        y = b;
        isVertical = x == 5 || board[y][x+1] != id;

        if (isVertical)
            while (b < 6 && board[b++][x] == id) l++;
        else
            while (a < 6 && board[y][a++] == id) l++;
    }
    car() {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int board[6][6], id;
    unordered_map<int, car> cars;
    for (int y=0;y<6;y++)
        for (int x=0;x<6;x++)
            cin >> board[y][x];

    for (int y=0;y<6;y++)
        for (int x=0;x<6;x++) {
            id = board[y][x];
            if (!id || cars.find(id) != cars.end()) continue;
            cars[id] = car(board, x, y, id);
        }

    
}
