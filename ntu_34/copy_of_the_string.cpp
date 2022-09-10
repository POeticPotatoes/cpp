#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int getDiff(vector<char>& a, vector<char>& b, int n) {
    int d = 0;
    for (int i=0;i<n;i++)
        d += abs(a[i] - b[i]);
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    string s, t;
    cin >> n >> k;
    cin >> s >> t;

    vector<char> sv(s.begin(), s.end()), tv(t.begin(), t.end());
    int d = getDiff(sv, tv, n);

    sort(sv.begin(), sv.end());
    sort(tv.begin(), tv.end());

    int sd = getDiff(sv, tv, n) + k;

    cout << min(d, sd) << endl;
}
