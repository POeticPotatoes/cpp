#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n,w,h, c, sum=0;
    cin >> m >> n >> w >> h;
    vector<int> t(m);
    vector<int> d(n);
    vector<int> dn(n);
    vector<vector<int>> s(m);
    vector<vector<int>> available(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>> q;

    for (int i=0;i<m;i++) {
        cin >> c;
        t[i] = c/w;
        sum += c;
    }
    for (int i=0;i<n;i++) {
        cin >> d[i];
        sum -= d[i];
    }

    for (int i=0;i<m;i++) available[0].emplace_back(i);

    if (sum) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=0;i<n;i++) {
        for (auto a: available[i]) {
            q.push(pair<int,int>{t[a], a});
        }
        while (dn[i] != d[i]) {
            if (q.empty()) {
                cout << -1 << endl;
                return 0;
            }
            c = q.top().second;
            s[c].emplace_back(i);
            for (int j=0;j<w;j++) if (i+j<n) dn[i+j]++;
            q.pop();
            t[c]--;
            if (t[c] && i+w+h<n) available[i+w+h].emplace_back(c);
        }
    }
    cout << 1 << endl;
    for (int i=0;i<m;i++) {
        int first=0;
        for (auto j: s[i])
            cout << (!first++?"":" ") << j+1;
        cout << endl;
    }
}
