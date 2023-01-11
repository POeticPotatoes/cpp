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

ll A[200000], n;

int check(ll v) {
    ll prev = abs(A[0]-v), cur;
    FOR(i, 1, n) {
        cur = abs(A[i]-v);
        if(prev>cur)
            return false;
        prev = cur;
    }
    return true;
}

void solve() {
    cin>>n;
    REP(i, n) cin>>A[i];

    int result = check(A[0]);
    if (result) {
        cout<<A[0]<<endl;
        return;
    }
    ll l = 0, r=0;
    FOR(i, 1, n) {
        if (A[i]>A[0] && (!r || A[i]-A[0] < A[r]-A[0])) r=i;
        if (A[i]<A[0] && (!l || A[0]-A[i] < A[0]-A[l])) l=i;
    }
    if (check((A[r]+A[0]+1)/2)) {
        cout<<(A[r]+A[0]+1)/2<<endl;
        return;
    }
    if (check((A[l]+A[0])/2)) {
        cout<<(A[l]+A[0])/2<<endl;
        return;
    }
    cout<<-1<<endl;
    return;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
