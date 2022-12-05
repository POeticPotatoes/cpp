#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using LL = long long;

const int maxn = (int)5e5 + 5;

int n;
LL aa[maxn];
LL bb[maxn];
LL sum[maxn];

struct Tree {
    int no[maxn << 2];

    static int ls(int k) {
        return k << 1;
    }

    static int rs(int k) {
        return k << 1 | 1;
    }

    static int Mx(int a, int b) {
        if (aa[a] > aa[b]) {
            return a;
        } else {
            return b;
        }
    }

    void push_up(int k) {
        no[k] = Mx(no[ls(k)], no[rs(k)]);
    }

    void build_tree(int l, int r, int k) {
        if (l == r) {
            no[k] = l;
            return;
        }
        int mid = (l + r) / 2;
        build_tree(l, mid, ls(k));
        build_tree(mid + 1, r, rs(k));
        push_up(k);
    }

    int query(int l, int r, int k, int L, int R) {
        if (L <= l && r <= R) {
            return no[k];
        }
        int mid = (l + r) >> 1;
        if (R <= mid) {
            return query(l, mid, ls(k), L, R);
        } else if (L > mid) {
            return query(mid + 1, r, rs(k), L, R);
        } else {
            return Mx(query(l, mid, ls(k), L, R),
                      query(mid + 1, r, rs(k), L, R));
        }
    }
} tr;

LL Sum(int l, int r) {
    return sum[r] - sum[l - 1];
}

LL dp(int l, int r) {
    if (l == r) {
        return aa[l];
    }
    int rt = tr.query(1, n, 1, l, r);
    if (rt == l) {
        return std::max(dp(l + 1, r), aa[l] - Sum(l + 1, r));
    } else if (rt == r) {
        return std::max(dp(l, r - 1), aa[r] - Sum(l, r - 1));
    } else {
        return std::min(std::max(dp(l, rt - 1), aa[rt] - Sum(l, rt - 1)),
                        std::max(dp(rt + 1, r), aa[rt] - Sum(rt + 1, r)));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int Mx = 1;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> bb[i];
        if (bb[i] > bb[Mx]) {
            Mx = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        aa[i] = bb[(i + Mx - 1 - 1) % n + 1];
        sum[i] = sum[i - 1] + aa[i];
    }
    tr.build_tree(1, n, 1);
    std::cout << dp(1, n) << std::endl;
    return 0;
}