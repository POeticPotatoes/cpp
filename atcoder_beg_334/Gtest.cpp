#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define per(i, n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#define per2(i, l, r) for (int i = (r)-1; i >= (l); i--)
#define each(e, v) for (auto &e : v)
#define MM << " " <<
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using maxheap = priority_queue<T>;

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

template <typename T>
int flg(T x, int i) {
    return (x >> i) & 1;
}

int pct(int x) { return __builtin_popcount(x); }
int pct(ll x) { return __builtin_popcountll(x); }
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int botbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int botbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
    if (v.empty()) cout << '\n';
}

template <typename T>
void printn(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}

template <typename T>
int lb(const vector<T> &v, T x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
int ub(const vector<T> &v, T x) {
    return upper_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
void rearrange(vector<T> &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
    return ret;
}

template <typename T>
void reorder(vector<T> &a, const vector<int> &ord) {
    int n = a.size();
    vector<T> b(n);
    for (int i = 0; i < n; i++) b[i] = a[ord[i]];
    swap(a, b);
}

template <typename T>
T floor(T x, T y) {
    assert(y != 0);
    if (y < 0) x = -x, y = -y;
    return (x >= 0 ? x / y : (x - y + 1) / y);
}

template <typename T>
T ceil(T x, T y) {
    assert(y != 0);
    if (y < 0) x = -x, y = -y;
    return (x >= 0 ? (x + y - 1) / y : x / y);
}

template <typename S, typename T>
pair<S, T> operator+(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first + q.first, p.second + q.second);
}

template <typename S, typename T>
pair<S, T> operator-(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first - q.first, p.second - q.second);
}

template <typename S, typename T>
istream &operator>>(istream &is, pair<S, T> &p) {
    S a;
    T b;
    is >> a >> b;
    p = make_pair(a, b);
    return is;
}

template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
    return os << p.first << ' ' << p.second;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
        cerr << fixed << setprecision(15);
    }
} io_setup;

constexpr int inf = (1 << 30) - 1;
constexpr ll INF = (1LL << 60) - 1;
// constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;

template <int mod>
struct Mod_Int {
    int x;

    Mod_Int() : x(0) {}

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    static int get_mod() { return mod; }

    Mod_Int &operator+=(const Mod_Int &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator-=(const Mod_Int &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator*=(const Mod_Int &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    Mod_Int &operator/=(const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator++() { return *this += Mod_Int(1); }

    Mod_Int operator++(int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator--() { return *this -= Mod_Int(1); }

    Mod_Int operator--(int) {
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator-() const { return Mod_Int(-x); }

    Mod_Int operator+(const Mod_Int &p) const { return Mod_Int(*this) += p; }

    Mod_Int operator-(const Mod_Int &p) const { return Mod_Int(*this) -= p; }

    Mod_Int operator*(const Mod_Int &p) const { return Mod_Int(*this) *= p; }

    Mod_Int operator/(const Mod_Int &p) const { return Mod_Int(*this) /= p; }

    bool operator==(const Mod_Int &p) const { return x == p.x; }

    bool operator!=(const Mod_Int &p) const { return x != p.x; }

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod - 2);
    }

    Mod_Int pow(long long k) const {
        Mod_Int now = *this, ret = 1;
        for (; k > 0; k >>= 1, now *= now) {
            if (k & 1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const Mod_Int &p) { return os << p.x; }

    friend istream &operator>>(istream &is, Mod_Int &p) {
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

struct Low_Link {
    struct edge {
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    vector<int> ord, low;
    vector<bool> used;
    vector<int> articulation, bridge;
    const int n;
    int m;
    int cnt = 0;
    vector<int> cnt2;

    Low_Link(int n) : es(n), ord(n), low(n), used(n), n(n), m(0), cnt2(n, 0) {}

    void add_edge(int from, int to) {
        es[from].emplace_back(to, m);
        es[to].emplace_back(from, m);
        m++;
    }

    int _dfs(int now, int pre, int k) {
        used[now] = true;
        ord[now] = low[now] = k++;
        bool is_articulation = false;
        int cnt = 0;
        for (auto &e : es[now]) {
            if (e.id == pre) continue;
            if (!used[e.to]) {
                cnt++;
                k = _dfs(e.to, e.id, k);
                low[now] = min(low[now], low[e.to]);
                if (pre != -1 && low[e.to] >= ord[now]) cnt2[now]++, is_articulation = true;
                if (ord[now] < low[e.to]) bridge.push_back(e.id);
            } else {
                low[now] = min(low[now], ord[e.to]);
            }
        }
        if (pre == -1) cnt2[now] = cnt - 1;
        if (pre == -1 && cnt >= 2) is_articulation = true;
        if (is_articulation) articulation.push_back(now);
        return k;
    }

    void build() {
        fill(begin(used), end(used), false);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (!used[i]) k = _dfs(i, -1, k), cnt++;
        }
    }
};

void solve() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    auto IN = [&](int i, int j) { return 0 <= i && i < H && 0 <= j && j < W && S[i][j] == '#'; };

    auto ID = [&](int i, int j) { return W * i + j; };

    Low_Link G(H * W);

    rep(i, H) rep(j, W) {
        if (!IN(i, j)) continue;
        rep(k, 4) {
            int ni = i + dx[k], nj = j + dy[k];
            if (IN(ni, nj) && i + j < ni + nj) G.add_edge(ID(i, j), ID(ni, nj));
        }
    }

    G.build();

    auto v = G.articulation;
    vector<bool> is_articulation(H * W, false);
    each(e, v) is_articulation[e] = true;

    int a = 0, b = 0, c = 0;

    rep(i, H) rep(j, W) {
        if (!IN(i, j)) {
            c++;
            continue;
        }
        int k = ID(i, j);
        b++;
        // cout << i MM j MM is_articulation[k] MM sz(G.es[k]) << endl;
        if (empty(G.es[k])) {
            a--;
        } else if (is_articulation[k]) {
            a += G.cnt2[k];
        }
    }

    // cout << G.cnt MM c MM a MM b << endl;

    cout<< mint(a) <<"\n";
    cout << mint(G.cnt) - c + mint(a) / mint(b) << '\n';
    cout.flush();
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}
