#include <bits/stdc++.h>
using namespace std;

bool alice_move(int o, int odd, int even, int **v);

bool bob_move(int o, int odd, int even, int **v) {
    if (!even && !odd)
        return !(o%2);
    return ((!odd || alice_move(o, odd-1, even, v)) && (!even || alice_move(o, odd, even-1, v)));
}

bool alice_move(int o, int odd, int even, int **v) {
    if (!even && !odd)
        return !(o%2);

    if (v[odd][o]) {
        return v[odd][o]-1;
    }

    bool result = ((odd && bob_move(!o, odd-1, even, v)) || (even && bob_move(o, odd, even-1, v)));
    v[odd][o] = 1 + result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, odd=0, even, *visited[101];
        odd = 0;
        cin >> n;
        for (int i=0;i<101;i++)
            visited[i] = new int[2]{};
        long long b;
        for (int i=0; i<n;i++) {
            cin >> b;
            odd += b&1;
        }
        even = n-odd;
        if (alice_move(0, odd, even, visited))
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
        for (int i=0;i<101;i++)
            delete[] visited[i];
    }
}
