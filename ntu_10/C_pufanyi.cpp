#include <algorithm>
#include <iostream>

using LL = long long;

constexpr int maxn = (int) 1e6 + 5;
constexpr LL inf = 0x3f3f3f3f3f3f3f3f;

int n;
LL a[maxn];
LL b[maxn];

LL get_1(LL l, LL r, int t) {
    if (l == 0) {
        return 0;
    }
    r = std::min(r, (1LL << t) - 1);
    if (l > r) {
        return inf;
    }
    LL ans = 0;
    for (int i = t - 1; i >= 0; --i) {
        if ((l & (1LL << i)) != (r & (1LL << i))) {
            ans++;
            break;
        }
        if (l & (1LL << i)) {
            ans++;
        }
    }
    return ans;
}

LL get_2(LL l, LL r, int t) {
    l = std::max(l, 1LL << t);
    if (l > r) {
        return inf;
    }
    if ((l >> t) == (r >> t)) {
        return (l >> t) + get_1(l & ((1LL << t) - 1), r & ((1LL << t) - 1), t);
    } else {
        return std::min((l >> t) + get_1(l & ((1LL << t) - 1), (1LL << t) - 1, t), (l >> t) + 1);
    }
}

LL solve(int t) {
    LL l = 0, r = inf;
    for (int i = 1; i <= n; ++i) {
        LL d = b[i] * (1LL << t) - a[i];
        LL ll = d, rr = d + (1LL << t) - 1;
        l = std::max(ll, l);
        r = std::min(rr, r);
    }
    if (r < l) {
        return inf;
    }
//    std::cout << l << ' ' << r << ' ' << get_2(l, r, t) << std::endl;
    return std::min(get_1(l, r, t), get_2(l, r, t));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }
    bool flg = true;
    LL tk = b[1] - a[1];
    for (int i = 1; i <= n; ++i) {
        if (b[i] - a[i] != tk) {
            flg = false;
            break;
        }
    }
    LL ans = inf;
    if (flg && tk >= 0) {
        ans = tk;
    }
    for (int i = 1; i < 31; ++i) {
        ans = std::min(ans, i + solve(i));
//        std::cerr << i << ' ' << i + solve(i) << std::endl;
    }
    if (ans == inf) {
        std::cout << "-1\n";
    } else {
        std::cout << ans << '\n';
    }
    return 0;
}
