#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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
constexpr ll N = 3e5;

ll n, A[N];

void solve() {
    cin>>n;
    REP(i, n/2) cin>>A[i*2+1];
    vector<pair<ll, ll>> S;
    REP(i, n/2) S.eb(pair<ll, ll>{A[i*2+1], i*2});
    sort(all(S), greater<pair<ll, ll>>());
    ll c=n, i=0;
    MaxHeap<ll> q;
    while (c>0) {
        deb(c);
        if (i==S.size()) break;
        if (c==S[i].first) {
            q.push({S[i].second});
            c--;
            i++;
            continue;
        }
        if (c<S[i].first || q.size() < c-S[i].first)
            return (void) (cout<<-1<<endl);
        ROF(k, c, S[i].first) {
            deb(q.top(), k);
            A[q.top()] = k;
            q.pop();
        }
        c = S[i].first;
    }
    ROF(k, c, 0) {
        deb(q.top(), k);
        A[q.top()] = k;
        q.pop();
    }
    REP(k, n) cout<<A[k]<<" ";
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
