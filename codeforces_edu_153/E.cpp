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

string S;
ll m;

void solve() {
    cin>>S;
    cin>>m;
    ll n = S.size();
    vector<pair<ll, ll>> A(m);
    vll ANS(m);
    REP(i, m) cin>>A[i].first>>A[i].second;
    REP(i, m) ANS[i] = abs(A[i].first - A[i].second);

    vv<pair<ll, ll>> adj(n + 26*26);
    REP(i, n-1) {
        deb(S[i], S[i+1], S[i]-'a', S[i+1]-'a');
        ll k = n + (S[i]-'a')*26 + (S[i+1]-'a');
        adj[k].eb(i, 1);
        adj[i].eb(k, 0);
        adj[i].eb(i+1, 1);
        adj[i+1].eb(i, 1);
    }
    deb(adj);

    ll h = 26*26;
    REP(i, h) {
        if (adj[n+i].empty()) continue;
        deb((char) ('a'+i/26), (char) ('a'+i%26));
        vll D(n+h, INF);
        deque<ll> Q;
        Q.push_back(n+i);
        D[n+i] = 0;
        while (Q.size()) {
            auto v = Q.front();
            Q.pop_front();
            
            for (auto &[c, w]: adj[v]) {
                if (D[v]+w >= D[c]) continue;
                D[c] = D[v]+w;
                if (w) Q.push_back(c);
                else Q.push_front(c);
            }
        }
        
        REP(j, m) {
            ll res = D[A[j].first-1] + D[A[j].second-1];
            ANS[j] = min(ANS[j], res-1);
        }
    }

    REP(i, m) cout<<ANS[i]<<"\n";
}

int main() {
    int t=1;
    IO;
    // cin >> t;
    while (t--) solve();
}
