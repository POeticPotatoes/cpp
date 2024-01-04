#include <iostream>
#include <bitset>
#include <cstring>

using LL = long long;

const int maxn = 25;

int n;
int a[maxn];
int sum[1 << maxn];
int f[1 << maxn];

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    n++;
    for (int i = n; i >= 1; --i) {
        a[i] -= a[i - 1];
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = sum[0] = 0;
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum[i] = sum[i ^ (1 << j)] + a[j + 1];
                break;
            }
        }
//        std::cout << "sum " << std::bitset<6>(i) << ' ' << sum[i] << '\n';
    }
//    for (int i = n; i > 0; --i) {
//        std::cout << a[i] << ' ';
//    }
//    std::cout << std::endl;
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                int to = (i ^ (1 << j));
                if (a[j + 1] == 0 || sum[to] == 0) {
                    f[i] = std::min(f[i], f[to]);
                } else {
                    f[i] = std::min(f[i], f[to] + 1);
                }
//                if (i == 11 && to == 9) {
//                    std::cerr << std::bitset<6>(i) << ' ' << std::bitset<6>(to) << ' ' << sum[to] << std::endl;
//                }
            }
        }
//        if (i == 11 || i == 9) {
//            std::cout << std::bitset<6>(i) << ' ' << sum[i] << ' ' << f[i] << '\n';
//        }
    }
    std::cout << f[(1 << n) - 1] << '\n';
    return 0;
}
