#include <bits/stdc++.h>
using namespace std;
// clang-format off
namespace { enum operand_type_enum : uint32_t { RAW = 0, COMPOSED = 1 << 1, REQUIRE_PARAM = 1 << 2, }; template <class T> concept has_operand_type = requires() { { T::operand_type } -> convertible_to<uint32_t>; }; template <class T> class operand_type { public: inline static constexpr uint32_t value() { if constexpr (has_operand_type<T>) return T::operand_type; else return operand_type_enum::RAW; } }; template <class T> constexpr uint32_t operand_type_v = operand_type<decay_t<T>>::value();
template <class T> concept is_raw = ((operand_type_v<T> & RAW) == RAW); template <class T> concept is_composed = ((operand_type_v<T> & COMPOSED) == COMPOSED); template <class T> concept require_param = ((operand_type_v<T> & REQUIRE_PARAM) == REQUIRE_PARAM); template <class T> concept require_no_param = !require_param<T>; template <class left_t, class right_t> class composed_operation_t { public: inline static constexpr uint32_t operand_type = COMPOSED | operand_type_v<right_t> | operand_type_v<left_t>;
left_t left; right_t right; }; template <class left_t, class right_t> requires(is_composed<left_t> && (!is_composed<right_t>)) auto operator|(left_t&& left, right_t&& right) { return left.left | (left.right | right); } template <class left_t, class right_t> requires(is_raw<left_t>&& require_param<right_t>) auto operator|(left_t&& left, right_t&& right) { return composed_operation_t<left_t, right_t>(left, right); } namespace array_binding_details { template <typename T> class array_binding_t_full { public:
inline static constexpr uint32_t operand_type = RAW; T* array; int l, r; T* begin() { return array + l; } T* end() { return array + r + 1; } void resize(const size_t sz) { r = l + sz - 1; } }; class array_binding_t_l_r { public: inline static constexpr uint32_t operand_type = RAW; template <typename T> friend array_binding_t_full<T> operator|(T* array, const array_binding_t_l_r& binding) { return array_binding_t_full<T>{array, binding.l, binding.r}; } int l, r; }; class array_binding_t_l { public:
inline static constexpr uint32_t operand_type = REQUIRE_PARAM; array_binding_t_l_r operator|(const int r) const { return array_binding_t_l_r{l, r}; } int l; }; class array_binding_t_empty { public: inline static constexpr uint32_t operand_type = REQUIRE_PARAM; array_binding_t_l operator|(const int l) const { return array_binding_t_l{l}; } }; static_assert(has_operand_type<array_binding_t_empty>); static_assert(require_param<array_binding_t_empty>); } enum general_operation_t { REVERSE, };
enum comparable_operation_t { SORT, UNIQUE, PREFIX_MIN, PREFIX_MAX, }; enum integer_operation_t { PREFIX_AND, PREFIX_OR, PREFIX_XOR, }; enum number_operation_t { PREFIX_SUM, PREFIX_PROD, }; enum single_input_operation_t { NEXT_INPUT, }; enum array_input_operation_t { INPUT, INDEX_1, }; enum array_output_operation_t { OUTPUT_1LINE, OUTPUT_1_PER_LINE, }; template <typename container_t> auto operator|(container_t&& a, const general_operation_t& op) { switch (op) {
case REVERSE: reverse(a.begin(), a.end()); break; default: assert(false); }; return a; } template <typename container_t> auto operator|(container_t&& a, const comparable_operation_t& op) { switch (op) { case SORT: { sort(a.begin(), a.end()); break; }; case UNIQUE: { sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end()) - a.begin()); break; } case PREFIX_MIN: { auto begin = a.begin(); ++begin; while (begin < a.end()) { (*begin) = min(*begin, *(begin - 1)); begin++; } break; } case PREFIX_MAX: {
auto begin = a.begin(); ++begin; while (begin < a.end()) { (*begin) = max(*begin, *(begin - 1)); begin++; } break; } default: assert(false); } return a; } template <typename container_t> auto operator|(container_t&& a, const number_operation_t& op) { switch (op) { case PREFIX_SUM: { for (auto it = a.begin() + 1; it < a.end(); it++) (*it) += (*prev(it)); break; } case PREFIX_PROD: { for (auto it = a.begin() + 1; it < a.end(); it++) (*it) *= (*prev(it)); break; } default: assert(false); } return a; }
template <typename container_t> auto operator|(container_t&& a, const integer_operation_t& op) { switch (op) { case PREFIX_AND: { for (auto it = a.begin() + 1; it < a.end(); it++) (*it) &= (*prev(it)); break; } case PREFIX_OR: { for (auto it = a.begin() + 1; it < a.end(); it++) (*it) |= (*prev(it)); break; } case PREFIX_XOR: { for (auto it = a.begin() + 1; it < a.end(); it++) (*it) ^= (*prev(it)); break; } default: break; } return a; } template <typename container_t>
auto operator|(container_t&& a, const array_input_operation_t& op) { switch (op) { case INPUT: { for (auto&& x : a) cin >> x; break; } default: assert(0); } return a; } template <typename container_t> auto operator|(container_t&& a, const array_output_operation_t& op) { switch (op) { case OUTPUT_1LINE: { for (auto&& x : a) cout << x << ' '; cout << '\n'; break; } case OUTPUT_1_PER_LINE: { for (auto&& x : a) cout << x << '\n'; cout << '\n'; break; } default: assert(0); } return a; }
constexpr array_binding_details::array_binding_t_empty ARRAY; }
// clang-format on

#define MULTI_TEST
// #define SKIP_ASSERT
#ifdef SKIP_ASSERT
#define assert(x) (x)
#endif
int n, m;
int a[200001];
vector<int> g[200001];
int cnt;
int num[200001];
int low[200001];
int done[200001];
vector<int> s;
int comp[200001];
pair<int, int64_t> w[200001];
int cc;
void dfs(int u) {
    done[u] = 1;
    low[u] = num[u] = ++cnt;
    s.push_back(u);
    for (auto&& v : g[u]) {
        if (done[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (done[v] == 1) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {  // SCC
        cc++;
        w[cc] = {0, 0};
        int v = -1;
        while (v != u) {
            v = s.back();
            s.pop_back();
            done[v] = 2;
            comp[v] = cc;
            w[cc].first++;
            w[cc].second -= a[v];
        }
    }
}

vector<pair<int, int>> new_edges;

pair<int, int64_t> f[200001];
pair<int, int64_t> F(int u) {
    if (done[u] == 3) return f[u];
    done[u] = 3;
    f[u] = w[u];
    pair<int, int64_t> best = {0, 0};
    for (auto&& v : g[u]) best = max(best, F(v));
    f[u].first += best.first;
    f[u].second += best.second;
    return f[u];
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    fill(low, low + n + 1, 0);
    fill(num, num + n + 1, 0);
    fill(done, done + n + 1, 0);
    cnt = 0;
    cc = 0;
    s.clear();
    new_edges.clear();

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        if (v != u) g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) g[i] | UNIQUE;
    for (int i = 1; i <= n; i++)
        if (!done[i]) {
            dfs(i);
        }

    // for (int u = 1; u <= n; u++) cerr << comp[u] << " \n"[u == n];
    for (int u = 1; u <= n; u++) {
        for (auto&& v : g[u])
            if (comp[v] != comp[u]) {
                new_edges.emplace_back(comp[u], comp[v]);
            }
    }
    new_edges | UNIQUE;
    for (int i = 1; i <= cc; i++) g[i].clear();
    for (auto&& [u, v] : new_edges) {
        g[u].push_back(v);
    }
    pair<int, int64_t> ans = {0, -0};
    for (int i = 1; i <= cc; i++) ans = max(ans, F(i));
    cout << ans.first << ' ' << -ans.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    while (t--) solve();
}
