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

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 200;

ll n, t, sa, da, sb, db;
pair<ll, ll> A[N], a, b, ta, tb;

void solve() {
    cin>>n>>t;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    REP(i, n) cin>>A[i].first>>A[i].second;

    db = da = INF;
    REP(i, n) {
        if (abs(A[i].first - a.first) < da) {
            da = abs(A[i].first - a.first);
            sa = i;
            ta = {A[i].first, a.second};
        }
        if (abs(A[i].second - a.second) < da) {
            da = abs(A[i].second - a.second);
            sa = i;
            ta = {a.first, A[i].second};
        }
        if (abs(A[i].first - b.first) < db) {
            db = abs(A[i].first - b.first);
            sb = i;
            tb = {A[i].first, b.second};
        }
        if (abs(A[i].second - b.second) < db) {
            db = abs(A[i].second - b.second);
            sb = i;
            tb = {b.first, A[i].second};
        }
    }

    ld ansDir = sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));

    // use both
    ld ansBoth = da + db + 2*t;

    ld ansA = t + da + min(abs(A[sa].first - b.first), abs(A[sa].second - b.second));
    ld ansB = t + db + min(abs(A[sb].first - a.first), abs(A[sb].second - a.second));

    ld mn = min({ansDir, ansBoth, ansA, ansB});

    printf("%.10LF\n", mn);
    if (mn == ansDir) {
        return (void) (cout<<"1\n0 "<<b.first<<" "<<b.second<<"\n");
    }
    if (mn == ansBoth) {
        cout<<"4\n";
        cout<<"0 "<<ta.first<<" "<<ta.second<<"\n";
        cout<<sa+1<<" "<<A[sa].first<<" "<<A[sb].second<<"\n";
        cout<<sb+1<<" "<<tb.first<<" "<<tb.second<<"\n";
        cout<<"0 "<<b.first<<" "<<b.second<<"\n";
        return;
    }
    if (mn == ansA) {
        cout<<"3\n";
        cout<<"0 "<<ta.first<<" "<<ta.second<<"\n"<<sa+1<<" ";
        if (abs(A[sa].first - b.first) > abs(A[sa].second - b.second))
            cout<<b.first<<" "<<A[sa].second<<"\n";
        else cout<<A[sa].first<<" "<<b.second<<"\n";
        cout<<"0 "<<b.first<<" "<<b.second<<"\n";
        return;
    }
    cout<<"3\n0 ";
    if (abs(A[sb].first - a.first) > abs(A[sb].second - a.second))
        cout<<a.first<<" "<<A[sb].second<<"\n";
    else cout<<A[sb].first<<" "<<a.second<<"\n";
    cout<<sb<<" "<<tb.first<<" "<<tb.second<<"\n";
    cout<<"0 "<<b.first<<" "<<b.second<<"\n";
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
