#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, d;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> friends(n);

        for (int i=0;i<n;i++)
            cin >> friends[i];
        for (int i=0;i<n;i++) {
            cin >> d;
            friends[i] -= d;
        }
        sort(friends.begin(), friends.end());

        int start=0, end=n, count=0;
        while (--end > start) {
            if (friends[start] + friends[end] <= 0) {
                count++;
                start++;
            }
        }
        cout << count << endl;
    }
}
