#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 400;

ll a, b, c;
char A[N];

void solve() {
    cin>>a>>b>>c;
    char *p = A;
    ll x = b - !!a;
    if (x>0) { 
        if (!(x&1)) *p++ = '1';
        while (x>0) {
            *p++ = '0';
            *p++ = '1';
            x-=2;
        }
    } else if (b) *p++ = '1';
    if (c) {
        if (p==A) *p++ = '1';
        while (c-->0) *p++ = '1';
    }
    if (a) {
        *p++ = '0';
        while (a-->0) *p++ = '0';
    }
    *p = '\0';
    cout<<A<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
