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

ll a[2000005] = {0};
vector<int> primes;
vector<int> pows;
vector<int> apows[2000005];

void find_primes(int x) {
    for(int i=2;i<=sqrt(x);i++) {
        if(x%i == 0) {
            primes.eb(i);
            int cnt = 0;
            while(x%i == 0) {
                x /= i;
                cnt++;
            }
            pows.eb(cnt);
        }
    }
    if(x!=1) {
        primes.eb(x);
        pows.eb(1);
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    REP(i,n) cin >> a[i];
    find_primes(x);
    deb(primes);
    deb(pows);

    REP(i,n) {
        REP(j, primes.size()) {
            int cnt = 0;
            ll tmp = a[i];
            while(tmp%primes[j]==0) {
                tmp /= primes[j];
                cnt++;
            }
            apows[i].eb(min(cnt,pows[j]));
        }
    }

    REP(i,n) {deb(apows[i]);}

    map<vector<int>, int> mp;
    vector<int> ini; 
    REP(i,pows.size()) ini.eb(0);
    mp[ini] = 0;

    map<vector<int>,int> uniq;
    REP(i,n) uniq[apows[i]]++;

    for(auto &[vx, cnt]: uniq) uniq[vx] = min(35, cnt);

    for(auto &[vx,  cnt]: uniq) {
        deb(vx);
        deb(cnt);

        vector<pair<vector<int>,int>> q;
        for(auto &[v,val]: mp) {
            vector<int> vprv;
            FORN(i, 1, cnt) {
                vector<int> vsum;
                REP(j,pows.size()) vsum.eb(min(ll(pows[j]), v[j] + vx[j] * i));
                if(vsum==vprv) break;
                q.eb(vsum, val + i);
                vprv = vsum;
            }
        }

        for(auto p:q) {
            vector<int> vsum = p.first;
            int val = p.second;
            if(!mp.count(vsum)) mp[vsum] = val;
            else mp[vsum] = min(mp[vsum], val);
        }
    }

    if(mp.count(pows)) cout << mp[pows] << endl;
    else cout << -1 << endl;
}

int main() {
    IO;
    int t=1;
    // cin >> t;
    while (t--) solve();
}
