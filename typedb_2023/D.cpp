#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll i = (a); (i) > (b); (i)--)
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
const ll N = 3e5;

ll n, A[N], vis[N], cyc[N], W[N], orig, cur, s, swaps, id, ans;

void solve() {
    cin>>n;
    memset(vis+1, 0xff, sizeof(ll)*n);
    memset(cyc+1, 0, sizeof(ll)*n);
    memset(W+1, 0xff, sizeof(ll)*n);
    FORN(i, 1, n) {
        cin>>A[i];
        A[i] += i;
    }
    swaps = 0, swaps = 0;
    W[1] = 0;
    FORN(i, 1, n) {
        if (vis[i]>=0) continue;
        bool loop = false;
        cur = i, s = 0, id=i*n;
        while (cur>0 && cur<=n) {
            if (vis[cur] >= 0) {
                loop = vis[cur]/n == i || cyc[vis[cur]/n];
                break;
            }
            s++;
            vis[cur] = id++;
            cur = A[cur];
        }
        deb(i, loop, s);

        cyc[i]=loop;
        if (i==1) orig = s;
        else if (!loop) {
            if (cur<1 || cur>n) swaps += orig*s;
            else {
                if (vis[cur]/n == 1) W[i] = (vis[cur]-n);
                else W[i] = W[vis[cur]/n];
                if (W[i]<0) swaps += orig*s;
                else swaps += (W[i])*s;
            }
        } 
    }

    ans = swaps;
    deb(cyc[1], ans, orig);
    if (cyc[1]) {
        ans += orig*(n+1);
        deb(orig*(n+1));
    } else {
        ans += orig*(n+1);
        ans += (orig-1)*(orig)/2;
        ans += (n-orig)*(2*n+1);
        deb(orig*(n+1), (orig-1)*(orig)/2, (n-orig)*(2*n+1));
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
