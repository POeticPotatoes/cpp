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

#define ra(a, b) (a>0?(a+b-1)/b:(a-b+1)/b)

ll x, y;

void solve() {
    cin>>x>>y;
    if (x==y) {
        cout<<1<<endl<<x<<endl;
        return;
    }
    ll diff= abs(x-y);
    vector<ll> ans;
    ll n = diff*2, div = (diff+1)/2;
    cout<<n<<endl;
    ll a = ra(x, div), b = ra(y, div), cur, orig=a;
    deb(diff, div, a, b);
    while (div--) {
        cout<<(cur=a)<<" ";
        x -= a, y -= b;
        while (cur!=b) cout<<--cur<<" ";
        if (!div) a = orig;
        else a = ra(x, div), b = ra(y, div);
        // deb(x, y, div, a, b);
        while (++cur!=a) cout<<cur<<" ";
    }
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
