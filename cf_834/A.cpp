#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

auto v = "Yes";

void solve() {
    string s;
    cin >> s;
    int loc = -1;
    for (int i=0;i<3;i++)
        if (v[i]==s[0]) {
            loc = i;
            break;
        }
    if (loc == -1) {
        cout << "No" << endl;
        return;
    }
    for (auto c:s) {
        if (c != v[loc]) {
            cout << "No"<<endl;
            return;
        }
        loc = (loc+1)%3;
    }
    cout<<"Yes\n";
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
