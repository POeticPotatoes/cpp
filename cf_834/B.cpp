#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

void solve() {
    int m,s,cur,end=0;
    cin >> m >> s;

    bool visited[51]{};
    while (m--) {
        cin >> cur;
        if (visited[cur]) {
            cout << "NO" << endl;
            return;
        }
        visited[cur]=1;
        end = max(end,cur);
    }
    for (int i=0;i<end;i++)
        if (!visited[i])
            s-=i;
    while (s>0)
        s -= ++end;
    cout<<(!s?"YES":"NO")<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
