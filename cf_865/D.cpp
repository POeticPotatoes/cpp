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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll n, t, l, r, p, h;

int solve() {
    cin>>n;
    if (n==2) {
        cout<<"! 1 2 2 1\n";
        cout.flush();
        cin>>t;
        return t+2;
    }
    vv<ll> dis(n);
    vll ans(n+1);
    vll order(n+1);
    printf("+ %lld\n", n+1); cout.flush(); cin>>t;
    printf("+ %lld\n", n+2); cout.flush(); cin>>t;
    dis[0].eb(1);

    order[1] = 1;
    FORN(i, 2, n) order[i] = abs(order[i-1] - n-1) + (i&1);

    ll m = 0;
    FORN(i, 2, n) {
        printf("? 1 %lld\n", i); cout.flush(); cin>>t;
        dis[t].eb(i);
        m = max(m, t);
    }

    l = 1, r = n, p = dis[m][0], h = m;
    ans[p] = l++;
    ans[1] = m+1;
    if (dis[m].size()>1) { ans[dis[m][1]] = r--; }
    while (m-- && dis[m].size() == 1) ans[dis[m][0]] = l++;
    deb(ans, m, l, r);
    for (;m>0;m--) {
        printf("? %lld %lld\n", dis[m][0], p); cout.flush(); cin>>t;
        if (t == h-m) {
            ans[dis[m][0]] = l++;
            ans[dis[m][1]] = r--;
        } else {
            ans[dis[m][1]] = l++;
            ans[dis[m][0]] = r--;
        }
        deb(ans, m, h-m);
    }
    deb(ans, order);
    
    cout<<"!";
    FORN(i, 1, n) { printf(" %lld", order[ans[i]]); }
    FORN(i, 1, n) { printf(" %lld", order[n+1-ans[i]]); }
    cout<<endl;
    cout.flush();
    cin>>t;
    return t+2;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) if (!solve()) break;
}
