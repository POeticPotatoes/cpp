#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
// #define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
// #define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
// #define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
// #define REP(i, n) FOR(i, 0, n)
// #define all(x) (x).begin(), (x).end()
// #define eb emplace_back
typedef long long ll;
// typedef long double ld;
// typedef vector<ll> vll;
// template <typename T>
// using vv = vector<vector<T>>;
// template <typename T>
// using vvv = vector<vv<T>>;
// template <typename T, typename N>
// using um = unordered_map<T, N>;
// template <typename T>
// using MinHeap = priority_queue<T, vector<T>, greater<T>>;
// template <typename T>
// using MaxHeap = priority_queue<T>;
// 
constexpr int M = 998244353;
// constexpr int inf = (int)1e9;
// constexpr ll INF = 1e18;

const ll N = 4e5;

ll n, m, P[N];
void solve() {
    cin>>n>>m;
    P[1]=1;
    for (int i=2;i<=n;i++) {
        if (P[i]) continue;
        for (int j=i*2;j<=n;j+=i) P[j]=1;
    }

    // We need to use inclusion exclusion
    // // No we don't youfucking retard
    vector<pair<ll, ll>> INX;
    ll ans=m, cur=0, sum=0, k=m*m;
    for (int i=2;i<=n;i++, k=(k*m)%M) {
        if (i>m) cur=0;
        else if (!P[i]) {
            cur += m/i;
            deb(cur);
            for (auto [a,b]: INX) {
                INX.emplace_back(a*i, b+1);
                deb(i, a, b, a*i);
                if (b&1) cur -= m/(a*i);
                else cur += m/(a*i);
            }
            deb(cur);
            INX.emplace_back(i, 1);
        }
        ans = (ans*cur) %M;
        sum = (sum+(k-ans)%M)%M;
        deb(i, ans, sum, k);
    }
    cout<<sum<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
