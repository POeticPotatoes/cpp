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
const ll N = 2e5;

ll n, k, C[N]{0,1,1}, s, c, t, a, ans;
string A, B;

void solve() {
    cin>>n>>k>>A>>B;
    vll D;
    s=0;
    REP(i, n) {
        if (A[i] == B[i]) {
            s++;
            continue;
        }
        D.eb(s);
        s=0;
    }
    D.eb(s);
    a = D.size()-1;
    deb(D);
    if (a <= k) {
        cout<<C[n]<<"\n";
        return;
    }
    s = 1<<a;
    ans = 0;
    REP(i, s) {
        if (__builtin_popcountll(i) != k) continue;
        c = D[0];
        t = 0;
        REP(j, a) {
            if (i&(1<<j)) {
                c+=D[j+1]+1;
                if (n ==3 && k==1) { deb(a, i, j, c, t); }
                continue;
            }
            t += C[c];
            if (n ==3 && k==1) { deb(i, j, c, C[c], t); }
            c=D[j+1];
        }
        t += C[c];
        if (n ==3 && k==1) { deb(c, t, ans); }
        ans = max(ans, t);
    }
    cout<<ans<<endl;
}

int main() {
    FOR(i, 3, N)
        C[i] = C[i-1]*i/(i-2);
    REP(i, N) C[i] += i;
    REP(i, 20) {
        deb(i, C[i]);
    }
    int _=1;
    cin >> _; // Comment this out if there are no tests
    while (_--) solve();
}
