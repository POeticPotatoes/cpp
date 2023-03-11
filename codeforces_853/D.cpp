#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
// #define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
// #define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
// #define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
// #define REP(i, n) FOR(i, 0, n)
// #define all(x) (x).begin(), (x).end()
// #define eb emplace_back
typedef long long ll;
// typedef long double ld;
// typedef vector<ll> vll;
// template <typename T>
// using vv = vector<vector<T>>;
// template <typename T>
// using vvv = vector<vv<T>>;
// template <typename T, typename N>
// using um = unordered_map<T, N>;
// template <typename T>
// using MinHeap = priority_queue<T, vector<T>, greater<T>>;
// template <typename T>
// using MaxHeap = priority_queue<T>;
// 
// constexpr int M = 1e9+7;
// constexpr int inf = (int)1e9;
// constexpr ll INF = 1e18;

ll n;
string a, b;
vector<int> ans;

void eor(ll k) {
    ans.emplace_back(k);
    string c = a;
    for (int i=0;i<n;i++) {
        if (i+k>=n || i+k<0 || c[i+k]=='0') {
            // deb(k, i);
            continue;
        }
        a[i] ^= 1;
    }
    // deb(k, a);
}

int lef(string &s) { return s.find('1'); }
int rig(string &s) { for(int r=n;r--;) if (s[r]=='1') return r; return -1;}

void solve() {
    cin>>n;
    cin>>a>>b;
    ans.clear();
    ll al = lef(a), bl = lef(b);
    // deb(al, bl);
    if (al == -1) {
        cout<<(bl==-1?"0\n":"-1\n");
        return;
    }
    if (bl==-1) return (void) (cout<<"-1\n");
    if (al < bl) {
        for (int i=bl;i<n;i++) {
            if (a[i] != b[i]) eor(al-i);
        }
        ll br = rig(b);
        for (int i=bl;--i>=0;) {
            if (a[i] != b[i]) eor(br-i);
        }
    } else {
        ll ar = rig(a);
        for (int i=bl;i>=0;i--) {
            if (a[i] != b[i]) eor(ar-i);
        }
        al = bl;
        for (int i=bl;i<n;i++) {
            if (a[i] != b[i]) eor(al-i);
        }
    }
    cout<<ans.size()<<endl;
    for (auto i: ans) cout<<i<<" ";
    if (ans.size()) cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
