#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h, mc[100]{}, hc[100]{}, f;
    cin >> n >> m >> h;

    string ms[100], hs[100];
    vector<vector<int>> ans;

    for (int i=0;i<n;i++) {
        cin >> ms[i];
        for (auto c: ms[i]) mc[i] += c-'0';
    }
    for (int i=0;i<n;i++) {
        cin >> hs[i];
        for (auto c: hs[i]) hc[i] += c-'0';
        if ((hc[i] && !mc[i]) || (mc[i] && !hc[i])) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int x=0;x<n;x++)
        for (int y=0;y<m;y++)
            for (int z=0;z<h;z++)
                if (ms[x][y]-'0' && hs[x][z]-'0') ans.emplace_back(vector<int>{x, y, z});
    cout << ans.size()<< endl;
    for (auto a: ans) cout << a[0] << " " << a[1] << " " << a[2] << endl;
    
    ans.clear();
    for (int x=0;x<n;x++) {
        if (!hc[x]) continue;
        if (hc[x] > mc[x]) {
            f = ms[x].find('1');
            int z = 0,d=hc[x]-mc[x];
            for (int c=0;c<d;c++) {
                while (hs[x][z] == '0') z++;
                ans.emplace_back(vector<int>{x, f, z});
                z++;
            }
            for (int y=f;y<m;y++) {
                if (ms[x][y] == '1') {
                    while (hs[x][z] == '0') z++;
                    ans.emplace_back(vector<int>{x, y, z});
                    z++;
                }
            }
        } else {
            f = hs[x].find('1');
            int y = 0,d=mc[x]-hc[x];
            for (int c=0;c<d;c++) {
                while (ms[x][y] == '0') y++;
                ans.emplace_back(vector<int>{x, y, f});
                y++;
            }
            for (int z=f;z<h;z++) {
                if (hs[x][z] == '1') {
                    while (ms[x][y] == '0') y++;
                    ans.emplace_back(vector<int>{x, y, z});
                    y++;
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto a: ans) cout << a[0] << " " << a[1] << " " << a[2] << endl;
}
