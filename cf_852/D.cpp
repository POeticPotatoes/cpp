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
// constexpr int M = 1e9+7;
// constexpr int inf = (int)1e9;
// constexpr ll INF = 1e18;

const ll N = 3e5;

ll n, A[N], B[N];

void solve() {
    cin>>n;
    ll c;
    for(int i=1;i<=n;i++) {
        cin>>c;
        A[c]=i;
    }
    for(int i=1;i<=n;i++) {
        cin>>c;
        B[c]=i;
    }
    ll l=0, r=n, ans=1;
    l = min(A[1], B[1]);
    r = max(A[1], B[1]);
    ans += (l-1)*(l-2)/2;
    ans += l-1;
    deb(ans);
    ans += (n-r)*(n-r-1)/2;
    ans += n-r;
    deb(ans);
    ans += (r-l-1)*(r-l-2)/2;
    ans += r-l-1;
    deb(ans);

    for (int i=2;i<=n;i++) {
        deb(i, l, r, ans);
        if ((A[i]<l || A[i]>r) && (B[i]<l || B[i]>r)) {
            ll z = 0, m = n+1;
            if (A[i] < l) z=A[i];
            else m = A[i];
            if (B[i] < l) z=max(z, B[i]);
            else m = min(m, B[i]);
            deb(z, m, l-z, m-r);
            ans += (l-z) * (m-r);
        }
        l = min({l, A[i], B[i]});
        r = max({r, A[i], B[i]});
    }
    cout<<ans<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
