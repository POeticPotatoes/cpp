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
constexpr ll N = 2e5;

int n, DP[N][4][4], ans, c;
string a, b;

int get(int i, int j, int k) {
    if (j<0 || k<0) return inf;
    return min({DP[i][j][k], get(i, j-1, k), get(i, j-1, k-1)});
}

bool compare(int p1, int p2) {
    return (p1>=a.size() || p2>=b.size())? 0 : a[p1]!=b[p2];
}

void solve() {
    cin>>a>>b;
    if (a.size()>b.size()) swap(a,b);
    n=a.size();
    memset(DP, 0x3f, sizeof(int[4][4])*n);

    DP[0][0][0] = a[0] != b[0];
    FOR(i, 1, n) DP[i][0][0] = DP[i-1][0][0] + (a[i] != b[i]);

    for (int j=1;j<4;j++)
        for (int k=0;k<=j;k++)
            DP[0][j][k] = compare(k, j-k);

    for (int i=1;i<n;i++)
        for (int j=1;j<4;j++)
            for (int k=0;k<=j;k++) {
                c = compare(i+k, i+j-k);
                DP[i][j][k] = min(DP[i-1][j][k], get(i-1, j, k)) + c;
            }
    ans = inf;
    for (int j=0;j<4;j++)
        for (int k=0;k<=j;k++) {
            // printf("(%d %d): " , j, k);
            // REP(i, n) printf("%d ", DP[i][j][k]);
            c = j + DP[n-1][j][k]+abs(n-((int)b.size())+j-2*k);
            // printf("(%d) \n" , c);
            ans = min(ans, c);
        }
    switch(ans) {
        case 0: return (void) (printf("You're logged in!\n"));
        case 1: return (void) (printf("You almost got it. You're wrong in just one spot.\n"));
        case 2: return (void) (printf("You almost got it, but you're wrong in two spots.\n"));
        case 3: return (void) (printf("You're wrong in three spots.\n"));
    }
    printf("What you entered is too different from the real password.\n");
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
