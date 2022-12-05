#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using LL = long long;

const int maxn = 5005;

int n, w;
std::string s[maxn];
int aa[maxn];
int f[maxn];
int to[maxn];

bool check(int rw) {
    memset(f, 0x3f, sizeof(f));
    f[n + 1] = 0;
    for (int i = n; i >= 1; --i) {
        int mx = aa[i];
        for (int j = 1; j <= rw && i + j <= n + 1; ++j) {
            mx = std::max(aa[i + j - 1], mx);
            if (mx + 1 + f[i + j] < f[i]) {
                f[i] = mx + 1 + f[i + j];
                to[i] = i + j;
            }
        }
    }
    return f[1] <= w;
}

int bbb[maxn];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> w;
    w++;
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];
        aa[i] = (int)s[i].length();
    }
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
//        std::cout << "bin sea" << ' ' << l << ' ' << r << std::endl;
    }
    check(l);
//    for (int i = 1; i <= n; ++i) {
//        std::cout << to[i] << ' ';
//    }
//    std::cout << std::endl;
    int a = l, b = 0;
    int now = 1;
    while (now <= n) {
        b++;
        now = to[now];
    }
    std::vector<std::vector<std::string>> output(a + 1, std::vector<std::string>(b + 1));
    now = 1;
    b = 0;
    while (now <= n) {
        b++;
        int noww = 1;
        int maxl = 0;
        for (int i = now; i < to[now]; ++i, ++noww) {
            output[noww][b] = s[i];
            maxl = std::max(maxl, aa[i]);
        }
        bbb[b] = maxl;
        for (int i = 1; i <= a; ++i) {
            while (output[i][b].length() <= maxl) {
                output[i][b].push_back(' ');
            }
        }
        now = to[now];
    }
    std::cout << a << ' ' << b << '\n';
    for (int i = 1; i <= b; ++i) {
        std::cout << bbb[i] << ' ';
    }
    std::cout << '\n';
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            std::cout << output[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}

/*
9 31
algorithm
contest
eindhoven
icpc
nwerc
programming
regional
reykjavik
ru
 */