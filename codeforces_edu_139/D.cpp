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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
const ll N = 1e7;

int a, b, x, PF[N+1]{}, ans, p;
vector<int> primes;

void solve() {
    cin>>a>>b;
    x = b-a;
    if (x==1) {
        cout<<"-1\n";
        return;
    }
    ans = inf;
    while (x>1) {
        p = PF[x];
        x /= p;
        ans = min(ans, (p-a%p)%p);
    }
    cout<<ans<<"\n";
}

int main() {
    IO;
    for(int i=2;i<=N;i++) {
        if (!PF[i]) {
            PF[i] = i;
            primes.eb(i);
        }
        for (auto j: primes) {
            if (i*j>N) break;
            PF[i*j] = j;
            if (!(i%j)) break;
        }
    }

    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
