#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
struct StringHash {
    ll n;
    const ll p1 = 998244353, p2 = 1'000'000'007;
    vector<ll> hashFrt, hashBck, fastExp;

    pair<ll, ll> hash(ll u, ll v) {
        if (v > n || u > v || u <= 0) return {-1, -1}; 
        ll hft = ((hashFrt[v] - hashFrt[u - 1] * fastExp[v - u + 1] % p2) + p2) % p2;
        ll hbk = ((hashBck[u] - hashBck[v + 1] * fastExp[v - u + 1] % p2) + p2) % p2;
        return {hft, hbk};
    }

    StringHash(const string& s) {
        n = s.length();
        hashFrt.resize(n + 2), hashBck.resize(n + 2), fastExp.resize(n + 2);
        fastExp[0] = 1;
        FOR(i, 1, n) fastExp[i] = fastExp[i - 1] * p1 % p2;
        FOR(i, 1, n) hashFrt[i] = (hashFrt[i - 1] * p1 % p2 + s[i - 1] - 'a') % p2;
        for (ll i = n; i >= 1; i--) hashBck[i] = (hashBck[i + 1] * p1 % p2 + s[i - 1] - 'a') % p2;
    }
};

const ll p = 998244353;  // TODO check if need __int128 for your modulus
ll norm(ll x) {
    x = (x % p + p) % p;
    return x;
}

struct Z;
Z power(Z, ll);

struct Z {
    ll x;
    ll normFast(ll t) {
        if (t >= p) return t - p;
        if (t < 0) return t + p;
        return t;
    }
    Z(ll t = 0) : x(norm(t)) {}
    ll val() const { return x; }
    Z operator-() const { return Z(norm(p - x)); }
    Z inv() const {
        assert(x != 0);
        return power(*this, p - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = ll(x) * rhs.x % p;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = normFast(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = normFast(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

Z power(Z a, ll b) {
    bool inv = false;
    if (b < 0) b = abs(b), inv = true;
    Z res = 1;
    for (; b; b /= 2, a *= a)
        if (b % 2) res *= a;
    if (inv) res = Z(1) / res;
    return res;
}

void solve() {
    string s, t; cin >> s >> t;

    vector<ll> pf(s.length()), pfe(s.length());
    StringHash hs(s), ht(t);

    for (ll i = 1; i <= s.length(); ++i) {
        ll lo = 1, hi = s.length() + 2; // first nonsame length, at least 1
        while (lo < hi) {
            ll mi = lo + hi >> 1; // test this length
            auto h1 = hs.hash(i, i + mi - 1),
                 h2 = ht.hash(1, 1 + mi - 1);
            if (h1.first != -1 && h1 == h2) lo = mi + 1;
            else hi = mi;
        };
        pf[i - 1] = lo - 1;
        if (i + pf[i - 1] - 1 < s.length() && pf[i - 1] < t.length()) {
            lo = 1, hi = s.length() + 2;  // first nonsame length, at least 1
            while (lo < hi) {
                ll mi = lo + hi >> 1;  // test [i + pf[i - 1] + 1, ... + mi - 1]
                auto h1 =
                    hs.hash(i + pf[i - 1] + 1, i + pf[i - 1] + 1 + mi - 1);
                auto h2 =
                    ht.hash(1 + pf[i - 1] + 1, 1 + pf[i - 1] + 1 + mi - 1);
                if (h1.first != -1 && h1 == h2)
                    lo = mi + 1;
                else
                    hi = mi;
            }
            pfe[i - 1] = pf[i - 1] + lo;
        } else pfe[i - 1] = pf[i - 1];

    }
    
    Z pval[3] = {0, 0, 0}; // sum 1 (excl empty set), sum n, sum n^2
    vector<Z> diff[3]; // 0-idx

    auto apply = [&](ll u, ll v, ll k, Z x) {
        diff[k][u] += x;
        diff[k][v + 1] -= x;
    };

    for (ll i = 0; i <= 2; ++i) diff[i].resize(s.length() + 4);


    apply(0, 0 + pfe[0] - 1, 0, 1);
    apply(0, 0 + pfe[0] - 1, 1, 1);
    apply(0, 0 + pfe[0] - 1, 2, 1);
    for (ll t = 0; t <= 2; ++t) pval[t] += diff[t][0];

    for (ll i = 1; i < s.length(); ++ i) {
        // [i, i + pfe[i] - 1]
        ll u = i, v = i + pfe[i] - 1;
        
        apply(u, v, 0, pval[0]);
        apply(u, v, 1, pval[1] + pval[0]);
        apply(u, v, 2, pval[2] + 2 * pval[1] + pval[0]);

        for (ll t = 0; t <= 2; ++t) pval[t] += diff[t][i];
    }

    cout << pval[2].val() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int _ = 1;
    // cin >> _;
    while (_--) solve();
}
