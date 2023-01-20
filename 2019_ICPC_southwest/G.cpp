#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vv<T>>;
template <typename T, typename N>
using um = unordered_map<T, N>;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 101;

ll n, m, h;
vll A[N], B[N];
char s[N];
vector<tuple<int, int, int>> ans;

void solve() {
    scanf("%lld %lld %lld", &n, &m, &h);
    REP(i, n) {
        scanf("%s", s);
        REP(j, m) if (s[j]=='1')
            A[i].eb(j);
    }
    REP(i, n) {
        scanf("%s", s);
        REP(j, h) if (s[j]=='1')
            B[i].eb(j);
    }
    

    REP(i, n) {
        if (A[i].empty()^B[i].empty())
            return (void) (printf("%d\n", -1));
        auto p1 = A[i].begin();
        REP(j, m) {
            if (p1==A[i].end() || *p1>j) continue;
            auto p2 = B[i].begin();
            REP(k, h) {
                if (p2 == B[i].end() || *p2>k) continue;
                ans.eb(tuple<int,int,int>{i,j,k});
                p2++;
            }
            p1++;
        }
    }
    printf("%d\n", ans.size());
    for (auto i: ans)
        printf("%d %d %d\n", get<0>(i), get<1>(i), get<2>(i));

    ans.clear();
    REP(i, n) {
        int p1=0, p2=0;
        while (A[i].size()-p1>B[i].size())
            ans.eb(tuple<int,int,int>{i, A[i][p1++], B[i][0]});
        while (B[i].size()-p2>A[i].size())
            ans.eb(tuple<int,int,int>{i, A[i][0], B[i][p2++]});
        while(p1<A[i].size())
            ans.eb(tuple<int,int,int>{i, A[i][p1++], B[i][p2++]});
    }

    printf("%d\n", ans.size());
    for (auto i: ans)
        printf("%d %d %d\n", get<0>(i), get<1>(i), get<2>(i));
}

int main() {
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
