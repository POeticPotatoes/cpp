#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using LF = long double;

constexpr int maxn = (int)1e6 + 5;

LF aa[maxn];

LF ksm(LF a, int b) {
    LF ans = 1;
    for (; b; b >>= 1, a *= a) {
        if (b & 1) {
            ans *= a;
        }
    }
    return ans;
}

int main() {
    int n, i, k;
    std::cin >> n >> i >> k;
    LF ans = 0;
    for (int a = i; a <= n; ++a) {
        ans += (ksm((LF)a / n, k) - ksm((LF)(a - 1) / n, k)) * (a + 1);
    }
    ans /= 2;
    ans += i * ksm((LF)(i - 1) / n, k);
    printf("%.10Lf\n", ans);
    return 0;
}