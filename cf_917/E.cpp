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
    ll n, k;
    cin>>n>>k;
    if (k&1) return (void) (cout<<"No\n");
    vv<ll> ans(n, vll(n));

    auto print = [&] () {
        cout<<"Yes\n";
        REP(i, n) {
            REP(j, n) cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
    };

    if (!k) {
        print();
        return;
    }


    if (k==n*n-2 || k==2) {
        if (n==2) {
            ans[0][0]=1;
            ans[0][1]=1;
            print();
            return;
        }
        cout<<"No\n";
        return;
    }
    ll lef = k;
    if (k>>1&1) {
        ans[0][0] 
            = ans[0][1]
            = ans[1][0]
            = ans[1][2]
            = ans[2][1]
            = ans[2][2]
            =1;
        lef -= 6;

        if (k>>3) {
            ans[0][2]
                = ans[0][3]
                = ans[3][2]
                = ans[3][3]
                = 1;
            lef -= 4;
        }
    }
    deb(lef);
    for (int i=0;i<n;i+=2) {
        if (!lef) break;
        for (int j=0;j<n;j+=2) {
            if (!lef) break;
            if (i<4 && j<4) continue;
            ans[i][j] = ans[i+1][j]
                = ans[i][j+1] = ans[i+1][j+1]=1;
            lef -= 4;
        }
    }
    for (int i=0;i<4;i+=2) {
        if (!lef) break;
        for (int j=0;j<4;j+=2) {
            if (!lef) break;
            ans[i][j] = ans[i+1][j]
                = ans[i][j+1] = ans[i+1][j+1]=1;
            lef -= 4;
        }
    }
    print();
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
