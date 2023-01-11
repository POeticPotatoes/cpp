#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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

void solve() {
    int k, n;
    cin>>k>>n;
    int m = ((k-n)*2>0.25)?0:floor(sqrt(2*n - 2*k + 0.25) + 1.5);
    ll diff=0, cur=1, count=0;
    //cout<<k<<" "<<n<<" m: "<<m<<endl;
    for(int i=0;i<m;i++, count++) {
        if (count==k-1) break;
        cur+=diff;
        diff++;
        cout<<cur<<" ";
    }
    for(;count<k-1;count++) {
        cur++;
        cout<<cur<<" ";
    }
    cout<<n<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
