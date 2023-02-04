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
#define LSOne(S) ((S) & -(S))
#define vll vector<ll>

// 1-based Fenwick Tree
class FenwickTree {
private:
    vll ft;

public:
    FenwickTree(int m) {ft.assign(m+1, 0);}

    void build(const vll &f) {
        int m=f.size();
        ft.assign(m+1, 0);

        for (int i=1;i<m;i++) {
            ft[i] += f[i];
            if (i + LSOne(i)<m)
                ft[i+LSOne(i)] += ft[i];
        }
    }

    FenwickTree(const vll &f) {build(f);}

    // Counting value occurrences in vll
    // m - largest value
    FenwickTree(int m, const vll &s) {
        vll f(m+1);
        for (auto i:s) f[i]++;
        build(f);
    }

    ll rsq(int j) {
        ll ans=0;
        for (;j;j-=LSOne(j))
            ans+=ft[j];
        return ans;
    }

    ll rsq(int i, int j) { return rsq(j)-rsq(i-1); }

    // Updates a single value by v
    void update(int i, ll v) {
        for(;i<(int)ft.size();i+=LSOne(i))
            ft[i]+=v;
    }

    // Binary search for the first element greater than k
    int select(ll k) {
        int lo=1, hi=ft.size()-1;
        for (int i=0;i<30;i++) { // Works because 2^30 > 10^9
            int mid = (lo+hi)/2;
            (rsq(1,mid)<= k)? lo=mid: hi=mid;
        }
        return hi;
    }
};

class RUPQ {
private:
    FenwickTree ft;
public:
    RUPQ(int m) : ft(m) {}   
    
    void range_update(int ui, int uj, ll v) {
        ft.update(ui, v);
        ft.update(uj+1, -v);
    }

    ll point_query(int i) { return ft.rsq(i); }
};

ll n, q, a, b, c, A[300000];

int convert(int v) {
    int ans=0;
    for (;v;ans+=v%10, v/=10);
    return ans;
}

void solve() {
    cin>>n>>q;
    vector<vector<int>> V(n+1);
    for (int i=1;i<=n;i++) {
        cin>>c;
        V[i].emplace_back(c);
        while (c>=10) {
            c = convert(c);
            V[i].emplace_back(c);
        }
    }
    RUPQ ft(n);
    for(int i=0;i<q;i++) {
        cin>>a;
        if (a==1) {
            cin>>b>>c;
            ft.range_update(b, c, 1);
        } else {
            cin>>c;
            cout<<V[c][min((ll) V[c].size()-1, ft.point_query(c))]<<endl;
        }
    }
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
