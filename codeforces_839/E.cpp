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
int n;

void solve() {
    cin>>n;
    vector<int> A(n);
    REP(i, n) cin>>A[i];
    auto asc = A, dec=A;
    sort(all(asc));
    sort(all(dec), greater<int>());
    int a = n, b=n, o=0;
    for(int i=0;i<n;a-=(asc[i]==A[i]), b-=(dec[i]==A[i]), i++) {
        o += asc[i] != A[i] && dec[i] != A[i];
    }

    if (b-o >= a) 
        cout<<"First"<<endl;
    else if (a-o > b)
        cout<<"Second"<<endl;
    else cout<<"Tie"<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
