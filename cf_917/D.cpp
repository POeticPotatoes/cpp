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
const int M = MOD[3];
const int inf = (int)1e9;
const ll INF = 1e18;

struct fenwick {
    vll f;
    ll sz;
    fenwick(ll s) {
        f.resize(s+1);
        sz = s+1;
    }

    void add(ll p, ll v) {
        //deb("add", p, v);
        p++;
        for (ll i=p;i<sz;i+=i&-i) f[i]+=v;
    }

    ll query(ll p) {
        ll ans = 0;
        p++;
        for (ll i=p;i;i-=i&-i) ans+=f[i];
        //deb("query", p, ans);
        return ans;
    }
};

void solve() {
    ll n, m;
    cin>>n>>m;
    vll A(n), B(m);
    REP(i, n) cin>>A[i];
    REP(i, m) cin>>B[i];

    fenwick af(n<<1), bf(m);
    ll x=0;
    ROF(i, m-1, -1) {
        x = (x+bf.query(B[i])) %M;
        bf.add(B[i], 1);
    }

    ll ans = (n * x)%M;
    cout.flush();

    ROF(i, n-1, -1) {
        ll c = A[i];
        REP(j, m) {
            ll v = ((m-j) * af.query(c));
            ans = (ans+v)%M;
            //deb(i, c, ans);
            c<<=1;
            if (c>=n<<1) {
                ans = ((((m-j-1) * (m-j)/2)%M * (n-1-i))%M + ans) %M;
                //deb(ans);
                break;
            }
        }
        //deb(i, ans);
        c = A[i]>>1;
        FOR(j, 1, m) {
            if (!c) break;
            ll v = ((m-j) * af.query(c));
            ans = (ans+v)%M;
            c>>=1;
        }
        af.add(A[i], 1);
        //deb(i, ans);
    }
    cout<<ans<<"\n";
}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
