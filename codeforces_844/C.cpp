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

ll n, sqr, t, digits[26], ans;
string s;

ll check(ll k, vector<pair<ll,ll>> &vals) {
    ll num = n/k, a=0;
    REP(i, k) a += abs(num-vals[i].first);
    FOR(i, k, 26) a += vals[i].first;
    a/=2;
    return a;
}

void solve() {
    cin>>n>>s;
    vector<ll> factors;
    memset(digits, 0, sizeof(digits));
    REP(i, n) digits[s[i]-97]++;
    vector<pair<ll, ll>> vals;
    REP(i, 26) vals.eb(pair<ll,ll>{digits[i], i});
    sort(all(vals), greater<pair<ll,ll>>());
    
    pair<ll, ll> m = {inf, inf};
    FOR(i, 1, min(27ll,n+1))
        if (!(n%i)) m = min(pair<ll, ll>{check(i, vals), i}, m);
    ll num = n/m.second;
    stack<char> avail;
    REP(i, m.second) {
        digits[vals[i].second] = num-vals[i].first;
        if (vals[i].first<num)
            avail.push(vals[i].second+97);
    }
    FOR(i, m.second, 26) digits[vals[i].second] = -vals[i].first;

    REP(i, n) {
        if (digits[s[i]-97]>=0) continue;
        while (digits[avail.top()-97]<1)
            avail.pop();
        digits[s[i]-97]++;
        s[i] = avail.top();
        digits[avail.top()-97]--;
    }
    cout<<m.first<<endl<<s<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
