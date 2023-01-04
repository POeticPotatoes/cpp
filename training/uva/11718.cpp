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

constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

ll n, k, s, MOD, c;

ll modPow(ll x, ll y) {
    ll res=1;
    while (y) {
        if (y&1) res = (res*x)%MOD;
        y >>= 1;
        x = (x*x)%MOD;
    }
    return res%MOD;
}

void solve() {
    cin>>n>>k>>MOD;
    s=0;
    REP(i,n) {
        cin>>c;
        s = (s+c)%MOD;
    }
    cout<<((s*k)%MOD*modPow(n,k-1))%MOD<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    REP (_,t) {
        cout<<"Case "<<_+1<<": ";
        solve();
    }
}
