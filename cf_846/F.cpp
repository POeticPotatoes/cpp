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

const ll N  = 3e5;

ll P[N+1]{}, last[N+1]{};
vll primes;

void solve() {
    ll n;
    cin>>n;
    vll A(n);
    REP(i, n) cin>>A[i];
    sort(all(A), greater<ll>());

    vll CNT(N+1), S(N+1);

    ll ans=0;
    deb(A);
    ROF(i, n-1, -1) {
        ll v = (n-i-2)*(n-i-1)/2, 
           cnt = 0, sum = 0;

        vll div;
        ll t=A[i];

        while (t>1) {
            ll p = last[t];
            ll m = div.size();
            REP(j, m) div.eb(div[j]*p);
            div.eb(p);
            while (!(t%p)) t/=p;
        }

        for (ll d: div) {
            if (P[d]&1) {
                cnt += CNT[d];
                sum += S[d];
            } else {
                cnt -= CNT[d];
                sum -= S[d];
            }
            CNT[d]++;
            S[d]+=i;
        }
        deb(cnt, sum);
        sum -= cnt*(i+1);
        ans += v-sum;
        deb(A[i], v, cnt, sum, ans);
    }
    cout<<ans<<"\n";
}

void init() {
    FORN(i, 2, N) {
        if (P[i]) continue;
        primes.eb(i);
        for (ll j=i;j<=N;j+=i) {
            last[j] = i;
            if (P[j]>=0) P[j]++;
        }
        for (ll j=i*i;j<=N;j+=i*i) P[j]=-1;
    }

    // REP(i, 20) {
    //     deb(primes[i]);
    // }

    // FORN(i, 2, 20) {
    //     deb(i);
    //     deb(P[i]);
    // }
}

int main() {
    int t=1;
    IO;
    init();
    // cin >> t;
    while (t--) solve();
}
