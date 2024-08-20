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

void solve() {
    ll n;
    cin>>n;
    vll A(n);
    REP(i, n) cin>>A[i];
    ll sum=0;
    REP(i, n) sum += A[i];
    if (sum%n) return (void) (cout<<"No\n");
    ll m = sum/n;

    vll req(40), fr(40), tot(40);

    REP(i, n) {
        if (A[i] == m) continue;
        ll sub, add;
        if (A[i]>m) {
            ll d = A[i]-m;
            sub = log2(d&-d);
            ll h;
            for (int t=d;t;h=t&-t, t-=t&-t);
            add = log2(h)+1;
            if (d != (1<<add) - (1<<sub))
                return (void) (cout<<"No\n");
            if (add-sub==1) {
                fr[sub]++;
                tot[sub]++;
                continue;
            }
        } else {
            ll d = m-A[i];
            add = log2(d&-d);
            ll h;
            for (int t=d;t;h=t&-t, t-=t&-t);
            sub = log2(h)+1;
            if (d != (1<<sub) - (1<<add))
                return (void) (cout<<"No\n");
            if (sub-add==1) {
                fr[add]--;
                tot[add]++;
                continue;
            }
        }
        req[add]++;
        req[sub]--;
    }
    // deb(m, req, fr, tot);

    REP(i, 39) {
        // deb(i, req[i], fr[i]);
        if (abs(req[i]) > tot[i]) {
            // deb(i, req[i], tot[i]);
            return (void) (cout<<"No\n");
        }
        ll rem;
        if ((req[i]<0) != (fr[i]<0)) {
            rem = fr[i]+req[i];
        } else {
            req[i+1] += req[i];
            rem = fr[i]-req[i];
        }
        if (rem%2 != 0) return (void) (cout<<"No\n");
        req[i+1] += rem/2;
    }
    cout<<"Yes\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
