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

ll n, c, C[N];
vector<pair<ll, ll>> A, B;

void solve() {
    cin>>n;
    A.clear();
    B.clear();
    REP(i, n) {
        cin>>c;
        A.eb(c, i);
        B.eb(c, i);
    }
    if (n==1) return (void) (cout<<"0\n");
    vector<pair<ll, ll>> pos, neg;
    
    sort(all(A));
    sort(all(B));
    bool posflag=true, negflag = true;
    // deb(A);

    if (A[n-1].first <= 0) posflag = false;
    while (posflag && A[0].first < 0 && A[n-1].first < abs(A[0].first)) {
        pos.eb(A[n-2].second, A[n-1].second);
        A[n-2].first += A[n-1].first;
        if (A[n-2] > A[n-1]) swap(A[n-2], A[n-1]);
    }
    for (auto &p: A) {
        if (p.first < 0) {
            pos.eb(p.second, A[n-1].second);
            p.first += A[n-1].first;
        }
        C[p.second] = p.first;
    }
    REP(i, n-1) if (C[i] > C[i+1]) pos.eb(i+1, i), C[i+1] += C[i];
    
    if (B[0].first >= 0) negflag = false;
    while (negflag && B[n-1].first > 0 && B[n-1].first > abs(B[0].first)) {
        neg.eb(B[1].second, B[0].second);
        B[1].first += B[0].first;
        if (B[1] < B[0]) swap(B[1], B[0]);
    }
    for (auto &p: B) {
        if (p.first > 0) {
            neg.eb(p.second, B[0].second);
            p.first += B[0].first;
        }
        C[p.second] = p.first;
    }
    ROF(i, n-1, 0) if (C[i] < C[i-1]) neg.eb(i-1, i), C[i-1] += C[i];
    // deb(neg);

    // deb(A, B);
    // deb(pos, neg);
    if (posflag && (!negflag || pos.size() < neg.size())) {
        cout<<pos.size()<<"\n";
        for (auto &[a, b] : pos) cout<<a+1<<" "<<b+1<<"\n";
    } else { cout<<neg.size()<<"\n"; for (auto &[a, b] : neg) cout<<a+1<<" "<<b+1<<"\n";
    }

}

int main() {
    int t=1;
    cin >> t;
    while (t--) solve();
}
