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

const ll N = 2;

struct Matrix {
    ll mat[N][N]{};

    friend Matrix operator * (Matrix a, Matrix b) {
        Matrix ans;
        for (int i=0;i<N;i++)
            for (int k=0;k<N;k++)
                if (a.mat[i][k]) for (int j=0;j<N;j++)
                    ans.mat[i][j] = (((a.mat[i][k] * b.mat[k][j]) %M + M)%M 
                                    + ans.mat[i][j]) %M;
        return ans;
    }
};

Matrix matPow(Matrix v, ll p) {
    if (!p) {
        Matrix ans;
        for(int i=0;i<N;i++) ans.mat[i][i]=1;
        return ans;
    }
    Matrix ans = matPow(v, p>>1);
    ans = ans*ans;
    if (p&1) ans = ans*v;
    return ans;
}

void solve() {
    Matrix fib = {{1,1,1,0}};
    auto ans = matPow(fib, 20);
    REP(i, N) {
        REP(j, N) cout<<ans.mat[i][j]<<" ";
        cout<<"\n";
    }
}

int main() {
    int t=1;
    // cin >> t;
    while (t--) solve();
}
