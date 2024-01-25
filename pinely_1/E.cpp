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

const ll MOD[] = {999727999, 1070777777, 1000000007, 998244353};
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
const int M = MOD[2];
const int inf = (int)1e9;
const ll INF = 1e18;

void solve() {
    ll n;
    cin>>n;
    vv<ll> adj(n);
    REP(i, n) {
        string s;
        cin>>s;
        REP(j, n) if (s[j]-'0') adj[i].eb(j);
    }

    vll vis(n);

    function<void(ll, vll &)> dfs = [&] (ll v, vll &vec) {
        vis[v] = 1;
        vec.eb(v);
        for (auto c: adj[v]) if (!vis[c]) dfs(c, vec);
    };

    ll cnt=0;
    vll cur, valid;

    REP(i, n) {
        if (!vis[i]) {
            vll comp;
            dfs(i, comp);

            if (comp.size() == n) return (void) (cout<<0<<"\n");

            deb(i, comp);

            for (auto v: comp) if (adj[v].size() != comp.size()-1) {
                ll sm = -1;
                for (auto c: comp) if (sm==-1 || adj[sm].size() > adj[c].size()) {
                    sm=c;
                }
                cout<<"1\n"<<sm+1<<"\n";
                return;
            }
            if (cur.empty() || cur.size() > comp.size()) cur = comp;
            valid.eb(i);
            cnt++;
        }
    }
    deb(cnt);
    if (cnt==2) {
        cout<<cur.size()<<"\n";
        for (auto v: cur) cout<<v+1<<" ";
        cout<<"\n";
        return;
    }
    if (cur.size()==1) {
        cout<<1<<"\n";
        cout<<cur[0]+1<<"\n";
        return;
    }
    cout<<2<<"\n"<<valid[0]+1<<" "<<valid[1]+1<<"\n";
}

int main() {
    IO;
    int t=1;
    cin >> t;
    while (t--) solve();
}
