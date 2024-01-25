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

const ll MOD[] = {999727999, 1070777777, 1000000007, 998244353};
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
const int M = MOD[2];
const int inf = (int)1e9;
const ll INF = 1e18;

const ll N = 20;

void solve() {
    ll n, q, req=0, sum=0;
    cin>>n>>q;
    vll A(n), DPcnt(1<<N|1), Q(q);
    vv<ll> DPsum(1<<N|1, vll(N));
    REP(i, n) cin>>A[i];
    REP(i, q) cin>>Q[i];

    REP(i, n) {
        DPcnt[A[i]]++;
        req += (1<<20) - A[i];
        sum += A[i];

        ll c=0;
        REP(j, N) {
            c |= 1<<j & A[i];
            DPsum[A[i]][j] += c;
        }
    }

    // SOS DP
    REP(i, N) REP(j, 1<<N)
        if (!(j>>i&1)) {
            DPcnt[j] += DPcnt[1<<i|j];
            REP(k, N) DPsum[j][k] += DPsum[1<<i|j][k];
        }

    REP(x, q) {
        ll v = Q[x];
        if (v >= req) {
            v += sum;
            cout<<v/n<<"\n";
            continue;
        }
        ll ans = 0;
        ROF(i, N-1, -1) {
            ll d = 1<<i | ans;
            ll r = (1<<i)*(n-DPcnt[d]);
            r -= DPsum[ans][i] - DPsum[d][i];
            // deb(i, r, ans, DPcnt[d], DPsum[ans][i], DPsum[d][i]);

            if (r <= v) {
                v -= r;
                ans = d;
            }
        }
        cout<<ans<<"\n";
    }
}

int main() {
    IO;
    int t=1;
    // cin >> t;
    while (t--) solve();
}
