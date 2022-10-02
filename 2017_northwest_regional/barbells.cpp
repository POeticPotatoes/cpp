#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
// #include <bits/stdc++.h>
#define vec vector

using namespace std;

// auto backtrack(vec<uint64_t>& plates, unordered_set<uint64_t>& comb, ) {

// }

auto index_int(int x, int i) { return (x >> i) & 1; }

auto k(vec<uint64_t>& plates) -> set<uint64_t> {
    int incl = 0;
    vec<bool> max(plates.size(), true);
    set<uint64_t> comb;
    set<uint64_t> res;
    int count = 0, j = plates.size() - 1;
    auto p = max.begin()._M_p;
    while (incl <= *p) {
        uint64_t sum = 0;
        for (int i = plates.size() - 1; i >= 0; --i) {
            if (index_int(incl, i)) {
                sum += plates[i];
            }
        }

        incl += 1;
        if(comb.find(sum) != comb.end()) {
            res.insert(sum);
        }
        comb.insert(sum);
    }

    return res;
}

auto solve() {
    int n, m;
    cin >> n >> m;
    vec<uint64_t> barbel(n);
    vec<uint64_t> plates(m);

    // comb.insert(0);

    for (int i = 0; i < n; ++i) {
        cin >> barbel[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> plates[i];
    }

    // comb = k(plates);
    unordered_set<uint64_t> comb = k(plates);

    // sort(plates.begin(), plates.end());

    // int l = 0, r = plates.size() - 1, start_l = 0;

    for (auto c : barbel) {
        for (auto k : comb) {
            cout << c + k << '\n';
        }
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
