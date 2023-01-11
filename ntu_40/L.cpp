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

constexpr ll MOD = 999983;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll S[51], O[51], nums[51], rev[MOD];

ll modPow(ll a, ll v) {
    a %= MOD;
    ll ans=1;
    while (v>0) {
        if (v&1) ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        v>>=1;
    }
    return ans;
}

void solve() {
    memset(S, 0, 51);
    memset(O, 0, 51);
    memset(nums, 0, 51);
    int n, m, l;
    cin>>n>>m>>l;

    REP(i, l) cin>>nums[i];

    if (m<=l) return (void) (cout<<0<<endl);
    cout<<1<<endl;
    FOR(i, 1, l+1) REP(j, l+1) S[i] = (S[i] + modPow(nums[j], i))%MOD;
    O[1] = S[1];
    FOR(i, 1, l+1) cout<<" "<<S[i];
    FOR(k, 2, l+1) {
        FOR(i, 1, k)
            O[k] = (O[k] + (((1-(i&1)*2) * O[i] * S[k-i])%MOD + S[k])%MOD)%MOD;
        cout<<"o"<<k<<": "<<O[k]<<endl;
        O[k] = -(O[k] * (1-(k&1)*2)*rev[k])%MOD;
    }
    cout<<l<<" 1";
    FOR(i, 1, l+1) cout<<" "<<O[i];
    cout<<endl;
}

int main() {
    IO;
    rev[1] = 1;
    for(int i=2;i<=MOD-1;++i)
        rev[i]=(long long)(MOD-MOD/i)*rev[MOD%i]%MOD;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
