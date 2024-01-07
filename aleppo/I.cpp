#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (int i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (int i = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int i = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 0, n)
#define aint(x) (x).begin(), (x).end()
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef vector<int> vll;
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

const int MOD[] = {999727999, 1070777777, 1000000007, 998244353};
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
const int M = MOD[2];
const int inf = (int)1e9;
const int INF = 1e18;

int vis[1000005];

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    vv<pair<int, int>> field(n+1);
    REP(i, m) {
        int p, t;
        scanf("%d %d", &p, &t);
        if (t<p) continue;
        field[p].eb(t, 0);
    }
    FORN(i, 1, n) sort(aint(field[i]));
    int b=n+1;
    memset(vis, 0, sizeof(int)*(n+1));
    ROF(i, n, 0) {
        for (auto &[p, v]: field[i]) {
            if (p-i>=0) v = !vis[p-i]++;
            if (!(p-i)) b=i;
        }
    }

    int avail=1e6;
    int ans = avail+n+1;
    FORN(i, 0, n) if (!vis[i]) {
        avail = i;
        break;
    }

    REP(i, b) {
        int h = field[i].empty()?1e6:field[i][0].first-1-i;
        if (avail <= h) ans = avail+n+1;
        for (auto &[p, v]: field[i]) {
            if (v) avail=min(avail, p-i);
        }
    }

    printf("%d\n", ans);
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
