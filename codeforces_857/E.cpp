#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define LSOne(S) ((S) & -(S))
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (int i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (int i = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int i = (a); (i) > (b); (i)--)
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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
const ll N = 3e5;

int ft[N], n, m, A[N], B[N], C[N];

int rsq(int j) {
    int ans=0;
    for (;j;j-=LSOne(j))
        ans=max(ans, ft[j]);
    return ans;
}
void update(int i, int v) {                          // Update a single value by v
    for(;i<=m && ft[i]<v;i+=LSOne(i))
        ft[i] = v;
}

void solve() {
    cin>>n;
    vector<pair<int, pair<int,int>>> hp;

    m = 0;
    REP(i, n) {
        int a, b;
        A[i] = C[i] = 0;
        cin>>a;
        REP(j, a) {
            cin>>b;
            if (b>A[i]) {
                hp.push_back({b, {i, C[i]++}});
                A[i] = b;
            }
        }
        m = max(m, A[i]);
    }
    sort(all(hp));

    memset(ft, 0, sizeof(int)*(m+1));
    deb(hp);

    for (auto &t: hp) {
        auto &[i, k] = t.second;
        deb(i, k, C[i], rsq(t.first-1));
        update(A[i], rsq(t.first-1)+C[i]-k);
    }
    cout<<rsq(m)<<endl;
}

int main() {
    int t=1;
    IO;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
