#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll i = (a); (i) <= (b); (i)++);
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
constexpr ll N = 2e5;

ll n, m, s, c;

void solve() {
    cin>>n>>m;
    vector<vector<bool>> A(n, vector<bool>(m));
    vector<pair<int, int>> S(n);
    vector<tuple<int, int, int>> ans;
    s=0;
    REP(i, n) {
        S[i] = {0, i};
        REP(j, m) {
            cin>>c;
            S[i].first += c;
            A[i][j] = c;
        }
        s += S[i].first;
    }
    deb(s);
    if (s%n) return (void) (cout<<-1<<endl);
    s /= n;
    deb(S);
    sort(all(S), greater<pair<int, int>>());
    vector<set<int>> P(m);
    c = 0;
    for (;S[c].first>s;c++) REP(i, m)
        if (A[S[c].second][i]) P[i].insert(c);
    if (!c) return (void) (cout<<0<<endl);
    deb(c, s);
    for (;S[c].first==s;c++);
    for (;c<n;c++) {
        int i=0;
        deb(c, S.size());
        while (S[c].first<s) {
            deb(S[c].first, i);
            if (!A[S[c].second][i]) {
                deb(P[i].size(), P[i]);
                while (P[i].size()) {
                    auto k = P[i].begin();
                    if (S[*k].first==s) {
                        deb(*k, S[*k], s, P[i]);
                        P[i].erase(k); 
                        continue;
                    }
                    ans.eb(S[c].second+1, S[*k].second+1, i+1);
                    S[*k].first--, S[c].first++;
                    P[i].erase(k); 
                    break;
                }
            }
            i++;
        }
    }
    cout<<ans.size()<<endl;
    for (auto t: ans)
        cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
