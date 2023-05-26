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

string A;
bool z=0;

bool isInt(char c) {return c<='9' && c>='0';}
bool valid(char c, int v) {
    deb(c, v);
    if (c=='X' && !v && z) return 0;
    return c=='0'+v || c=='X' || c=='_';
}

// bruh lazy
void solve() {
    cin>>A;
    ll n = A.size(), x=0, ans=1, c=0;
    if (n==1) return (void) (cout<<valid(A[0], 0)<<endl);
    if (A[0]=='0') return (void) (cout<<"0"<<endl);
    REP(i, n-2) {
        x += A[i] == 'X';
        if (A[i] == '_') ans *= 10 - !i;
    }
    char a = A[n-2] , b = A[n-1];
    z = A[0]=='X';

    if (x && a!='X' && b != 'X') ans *= 10-z;
    if (a=='X' && b == 'X') return (void) (cout<<(z?0:ans)<<endl);
    FOR(i, 0, 10) {
        FOR(j, 0, 10) {
            if (n==2 && !i && !j) continue;
            if ((i*10+j)%25) continue;
            deb(i, j);
            if (!valid(a, i) || !valid(b, j)) continue;
            c++;
        }
    }
    cout<<ans*c<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
