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
const ll N = 4e5;

ll n, A[N], vis[N], m, c, s, t, nex;
map<ll, vll> adj;
vll fac[N];

void dfs() {
    queue<ll> q;
    q.push(s);
    vis[s] = 1;
    while (q.size()) {
        auto p = q.front();
        deb(p);
        for (auto f: fac[p])
            for (auto &j: adj[f]) {
                if (vis[j]) continue;
                vis[j] = vis[p]+1;
                if (j == t) return;
                q.push(j);
            }
        q.pop();
    }
}

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];
    cin>>s>>t;
    s--, t--;

    memset(vis, 0, sizeof(ll)*n);

    REP(i, n) {
        c = A[i];
        m = sqrt(c);
        FORN(j, 2, m)
            if (!(c%j)) {
                fac[i].eb(j);
                adj[j].eb(i);
                while (!(c%j)) c/=j;
            }
        if (c>1) {
            fac[i].eb(c);
            adj[c].eb(i);
        }
    }
    dfs();

    if (!vis[t]) return (void) (cout<<-1<<endl);
    cout<<vis[t]<<endl;
    c = t;

    vll P;
    while (c!=s) {
        P.eb(c);
        nex = -1;
        for (auto f: fac[c]) {
            for (auto &j: adj[f]) {
                if (!vis[j] || vis[j]>=vis[c]) continue;
                nex = j;
                break;
            }
            deb(nex);
            if (nex > -1) break;
        }
        c = nex;
    }
    P.eb(s);
    for(int i = P.size()-1;i>=0;i--)
        cout<<P[i]+1<<" ";
    cout<<endl;
}

int main() {
    solve();
}
