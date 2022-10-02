#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
// #include <bits/stdc++.h>
#define vec vector

using namespace std;

auto solve() {
    int n, m;
    cin >> n >> m;
    vec<vec<char>> mat(n, vec<char>(m, 0));
    unordered_map<int, int> no_apple;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int j = 0;
        for (char c : s) {
            mat[i][j] = c;
            if(c == 'o') {
                no_apple[j]++;
            }
            j++;
        }
    }

    // for (auto& c : mat[0]) {
    //     c = '.';
    // }

    int done_col = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = done_col; j < m; ++j) {
            char c = mat[i][j];
            if (c == '#') {
                int i_n = i - 1, j_n = j;
                done_col = j + 1;
                if (i_n >= 0 || i_n < n) {
                    mat[i_n][j_n] = 'o';
                    break;
                }
            }

            if (i + 1 == n) {
                // int k = 0, kj = j, ki = i;
                // mat[i][j] = 'o';
                int ki = i;
                while (ki > 0 && no_apple[j] > 0) {
                    
                    mat[ki][j] = 'o';
                    ki--;
                    no_apple[j]--;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mat[i][j];
        }
        cout << '\n';
    }
}

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 1;
    // cin >> n;
    while (n--) {
        solve();
    }
}
