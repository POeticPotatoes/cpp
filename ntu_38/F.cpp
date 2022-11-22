#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

bool collided(vector<string> &map, int y, int x, int r, int c) {
    if (y<0||y>r-2||x<0||x>c-2) return 1;
    return map[y][x]=='#' || map[y+1][x]=='#' || map[y+1][x+1]=='#' || map[y][x+1]== '#';
}

bool occupied(vector<string> &map, int y, int x, int r, int c) {
    if (y<0||y>r-1||x<0||x>c-1) return 1;
    return map[y][x] == '#';
}

bool won(vector<string> &map, int y, int x) {
    return map[y][x]=='O' || map[y+1][x]=='O' || map[y+1][x+1]=='O' || map[y][x+1]== 'O';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int r, c, x=-1,y, tx=-1,ty;
        cin >> r >> c;
        vector<string> map(r);
        int reached[1000][1000]={};

        for (int i=0;i<r;i++) cin >> map[i];
        
        //Locate yummamma and onion
        for (int a=0,b=0;b<c;a<r-1?a++:b++) {
            for (int i=a,j=b;i>=0&&j<c;i--,j++) {
                if (x==-1&&map[i][j]=='Y') {
                    y=i;x=j;
                }
                if (tx==-1&&map[i][j]=='O') {
                    ty=i;tx=j;
                }
            }
            if (x!=-1&&tx!=-1) break;
        }

        queue<pair<int,int>> q;
        q.push({y,x});
        bool found=false;
        
        while (q.size()) { 
            auto p = q.front(); q.pop();
            x = p.second, y = p.first;
            auto s = reached[y][x];
            if (reached[ty][tx] && s>reached[ty][tx]) continue;
            s++;
            if (won(map,y,x)) { 
                cout << reached[y][x] << endl;
                found = true;
                break;
            }
            
            if (!collided(map,y,x-1,r,c) && (!reached[y][x-1]||reached[y][x-1]>s)) {
                reached[y][x-1] = s; q.push({y,x-1});
            }
            if (!collided(map,y,x+1,r,c) && (!reached[y][x+1]||reached[y][x+1]>s)) {
                reached[y][x+1] = s; q.push({y,x+1});
            }
            if (!collided(map,y-1,x,r,c) && (!reached[y-1][x]||reached[y-1][x]>s)
                    && !collided(map, y-1,x,r,c)) {
                reached[y-1][x] = s; q.push({y-1,x});
            }
            if (!collided(map,y+1,x,r,c) && (!reached[y+1][x]||reached[y+1][x]>s)) {
                reached[y+1][x] = s; q.push({y+1,x});
            }
            if (!collided(map,y+1,x+1,r,c) && (!reached[y+1][x+1]||reached[y+1][x+1]>s
                   )&& (!occupied(map,y,x+2,r,c))
                    && (!occupied(map,y+2,x,r,c))) {
                reached[y+1][x+1] = s; q.push({y+1,x+1});
            }
            if (!collided(map,y+1,x-1,r,c) && (!reached[y+1][x-1]||reached[y+1][x-1]>s
                   )&& (!occupied(map,y,x-1,r,c))
                    && (!occupied(map,y+2,x+1,r,c))) {
                reached[y+1][x-1] = s; q.push({y+1,x-1});
            }
            if (!collided(map,y-1,x+1,r,c) && (!reached[y-1][x+1]||reached[y-1][x+1]>s
                   )&& (!occupied(map,y-1,x,r,c))
                    && (!occupied(map,y+1,x+2,r,c))) {
                reached[y-1][x+1] = s; q.push({y-1,x+1});
            }
            if (!collided(map,y-1,x-1,r,c) && (!reached[y-1][x-1]||reached[y-1][x-1]>s
                    )&& (!occupied(map,y-1,x+2,r,c))
                    && (!occupied(map,y+1,x-1,r,c))) {
                reached[y-1][x-1] = s; q.push({y-1,x-1});
            }
        }
        if (!found) cout << -1 << endl;
    }
}
