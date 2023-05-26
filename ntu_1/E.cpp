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

constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 600;

ll n, m, s, KMP[N], M[N];
string A, B;

void smin(ll &a, ll b) {a=a<b?a:b;}

void solve() {
    cin>>n>>m;
    cin>>A; cin>>B;
    s = n-m+2;
    // build kmp
    KMP[0] = 0;
    FOR(i, 1, m) { KMP[i] = B[i] == B[KMP[i-1]]?KMP[i-1]+1:
                            B[i] == B[0]?1:0; }
    // build mapping for wrong items
    M[0] = 0;
    FOR(i, 1, m)
        M[i] = B[KMP[i-1]]!=B[i]?KMP[i-1]+1:M[KMP[i-1]];

    // deb("KMP");
    // REP(i, m) cout<<KMP[i]<<" ";
    // cout<<endl;
    // deb("M");
    // REP(i, m) cout<<M[i]<<" ";
    // cout<<endl;
    
    // bottom-up DP, j: number of matches, k: length of current suffix
    vvv<ll> DP(n, vv<ll>(s+1, vll(m+1, INF)));
    DP[0][0][1] = !(DP[0][0][0] = A[0] == B[0]);
    if (m==1) DP[0][1][0] = A[0] != B[0];
    REP(i, n-1) {
        // deb(i);
        // REP(j, 2) {
        //     FORN(k, 0, m) {
        //         if (DP[i][j][k]>inf) cout<<"- ";
        //         else cout<<DP[i][j][k]<<" ";
        //     }
        //     cout<<endl;
        // }
        // deb(M[1+1], A[i+1], B[1], DP[i][0][1]);
        // cout<<endl;
        REP(j, s) {
            REP(k, m) {
                // assume k already match, check for next item
                smin(DP[i+1][j][k+1], DP[i][j][k] + (A[i+1]!=B[k]));
                // how many still match in the case that the item is wrong
                smin(DP[i+1][j][M[k]], DP[i][j][k] + (A[i+1]==B[k]));
            }
            smin(DP[i+1][j+1][KMP[m-1]], DP[i+1][j][m]);
            // deb(i, j, DP[i+1][j][m]);
        }
    }
    // deb(n-1);
    // REP(j, 2) {
    //     FORN(k, 0, m) {
    //         if (DP[n-1][j][k]>inf) cout<<"- ";
    //         else cout<<DP[n-1][j][k]<<" ";
    //     }
    //     cout<<endl;
    // }
    REP(i, s) {
        ll a = INF;
        REP(j, m) smin(a, DP[n-1][i][j]);
        cout<<(a>inf?-1:a)<<" ";
    }
    cout<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
