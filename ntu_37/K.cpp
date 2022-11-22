#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define MAX 5000
using namespace std;

vector<vector<int>> red(MAX), blue(MAX);
vector<vector<pair<int,bool>>> people(10000);
int n;

bool dfs(vector<int> *ans, vector<int> *visited, int cur) {
    while (cur < n && (*visited)[cur] > 1) cur++;
    if (cur == n) return true;
    int done = 0, marked = 0;
    for (auto i: (people)[cur]) {
        if ((*ans)[i.first]) {
            done += (*ans)[i.first] -1 == i.second;
            continue;
        }
        marked++;
        (*ans)[i.first] = i.second+1;
        if (i.second)
            for (auto j: blue[i.first])
                (*visited)[j]++;
        else for (auto j: red[i.first])
                (*visited)[j]++;
        cout << cur << ": marked " << i.first << endl;
    }
    if (done == 2 && dfs(ans, visited, cur+1)) return true;
    if (marked == 2 && dfs(ans, visited, cur+1)) return true;
    for (auto i: (people)[cur]) {
        if (i.second)
            for (auto j: blue[i.first])
                (*visited)[j]--;
        else for (auto j: red[i.first])
                (*visited)[j]--;
        cout << cur << ": unmarked " << i.first << endl;
        if (dfs(ans, visited, cur+1)) return true;
        if (i.second)
            for (auto j: blue[i.first])
                (*visited)[j]++;
        else for (auto j: red[i.first])
                (*visited)[j]++;
    }
    for (auto i: (people)[cur])
        if (i.second)
            for (auto j: blue[i.first])
                (*visited)[j]--;
        else for (auto j: red[i.first])
                (*visited)[j]--;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, f;
    char c;
    cin >> k >> n;
    vector<int> ans(k);
    vector<int> visited(n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<3;j++) {
            cin >> f;
            f--;
            cin >> c;
            people[i].emplace_back(pair<int,bool>{f, c=='B'});
            if (c=='B')
                blue[f].emplace_back(i);
            else
                red[f].emplace_back(i);
        }
    }
    if (!dfs(&ans, &visited, 0)) {
        cout << -1 << endl;
        return 0;
    }
    for (auto i : ans) cout << (ans[i]==2?'R':'B');
    cout << endl;
}
