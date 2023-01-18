#include <bits/stdc++.h>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 3e5;

ll n, m, d, A[N], B[N], D[N];
pair<ll,ll> q[N];
um<ll, ll> M;

ll get(ll a) {
    if (D[a] == a) return a;
    return get(D[a]);
}

void solve() {
    M.clear();
    cin>>n;
    REP(i, n) cin>>A[i];
    REP(i, n) cin>>B[i];
    cin>>m;
    REP(i, m) {
        cin>>d;
        M[d]++;
    }

    REP(i, n) if (A[i] < B[i])
        return (void) (cout<<"NO"<<endl);
    REP(i, n+1) D[i] = i;
    REP(i, n) q[i].first = B[i], q[i].second = i;
    sort(q, q+n);

    REP(i, n) {
        ll j=0;
        for (;i+j<n && q[i].first == q[i+j].first;j++);
        map<ll, ll> c;
        //cout<<q[i].first<<"'s j: "<<j<<endl;
        ROF(k, j-1, -1) {
            ll pos = q[i+k].second;
            //cout<<"pos: "<<pos<<endl;
            D[pos] = get(pos+1);
            if (A[pos] != B[pos]) c[D[pos]]++;
        }
        //REP(k, n) cout<<D[k]<<" ";
        //cout<<endl;
        //cout<<"Required for "<<q[i].first<<": "<<c.size()<<endl;
        if (c.size() > M[q[i].first]) return (void) (cout<<"NO"<<endl);
        i+=j-1;
    }
    cout<<"YES"<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
