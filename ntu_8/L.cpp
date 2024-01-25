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

vector<pair<ll ,ll>> randVec(int n) {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(1, 10); // define the range
    vector<pair<ll, ll>> ret;
    REP(_, n) ret.push_back({distr(gen), distr(gen)});
    return ret;
}

vll brute(vector<pair<ll, ll>> a){
    ll n = a.size();
    vll ans(n, INF);
    function<ll(ll)> calc = [&](ll k) {
        ll sum=0, m=0;
        REP(i, n) {
            if ((k>>i)&1) {
                sum += a[i].first;
                m = max(m, a[i].second);
            }
        }
        return sum+m;
    };

    FORN(i, 1, (1<<n)-1) {
        ans[__builtin_popcountll(i)-1] = min(ans[__builtin_popcountll(i)-1], calc(i));
    }
    return ans;
}

vll solve2(vector<pair<ll,ll>> a) {
    int n = a.size();
    multiset<pair<ll,ll>, greater<pair<ll,ll>>> st1;
    multiset<pair<ll,ll>, greater<pair<ll,ll>>> st2;
    ll sum = 0;

    REP(i, n) {
        int x = a[i].first, y = a[i].second;
        a[i] = {x,y};
        st1.insert({x,i});
        st2.insert({y,i});
        sum += x;
    }

    sum += st2.begin()->first;
    vll ans;
    ans.push_back(sum);
    int k = n;

    while(--k){
        auto minA = st1.begin(), min2A = next(minA);
        auto minB = st2.begin(), min2B = next(minB);
        ll costX = minA->first;
        ll costY = a[minB->second].first + (minB->first - min2B->first);
        if (costX > costY){
            sum -= costX;
            st2.erase({a[minA->second].second, minA->second});
            st1.erase(minA);
        }
        else {
            sum -= costY;
            st1.erase({a[minB->second].second, minB->second});
            st2.erase(minB);

        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vll solve3(vector<pair<ll,ll>> a) {
    int n = a.size();
    set<pair<ll , ll>> pq, pqa, pqb;

    REP(i, n) {
        int x = a[i].first, y = a[i].second;
        a[i] = {x,y};
        pq.insert({x+y, i});
        pqb.insert({y, i});
    }

    ll sum = 0;
    vll ans;
    int k = n;
    ll b = 0;

    while(k--){
        ll best = INF;
        int besti = -1;
        auto bestMore = pq.begin(), bestLess = pqa.begin();
        if (bestMore != pq.end()) {
            best = bestMore->first - b;
            besti = bestMore->second;
        }
        if (bestLess != pqa.end() && bestLess->first < best) {
            best = bestLess->first;
            besti = bestLess->second;
        }

        b = max(b, a[besti].second);
        int f = a[besti].first, s = a[besti].second;
        pq.erase({f+s, besti});
        pqa.erase({f, besti});
        pqb.erase({s, besti});

        while (pqb.begin() != pqb.end() && pqb.begin()->first <= b){
            auto xxx = pqb.begin();
            pqa.insert({a[xxx->second].first, xxx->second});
            pq.erase({a[xxx->second].first + a[xxx->second].second, xxx->second});
            pqb.erase(xxx);

        }

        sum += best;
        ans.push_back(sum);
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    pair<ll, ll> a[n];
    multiset<pair<ll,ll>, greater<pair<ll,ll>>> st1;
    multiset<pair<ll,ll>, greater<pair<ll,ll>>> st2;
    ll sum = 0;

    REP(i, n) {
        int x, y; cin >> x >> y;
        a[i] = {x,y};
        st1.insert({x,i});
        st2.insert({y,i});
        sum += x;
    }

    sum += st2.begin()->first;
    vll ans;
    ans.push_back(sum);
    int k = n;

    while(--k){
        auto minA = st1.begin(), min2A = next(minA);
        auto minB = st2.begin(), min2B = next(minB);
        ll costX = minA->first;
        ll costY = a[minB->second].first + (minB->first - min2B->first);
        if (costX > costY){
            sum -= costX;
            st2.erase({a[minA->second].second, minA->second});
            st1.erase(minA);
        }
        else {
            sum -= costY;
            st1.erase({a[minB->second].second, minB->second});
            st2.erase(minB);

        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    REP(i, n) cout << ans[i] << '\n';



}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    // while (t--) solve();
    //
    
    while (true){
        int n; cin >> n;
        vector<pair<ll, ll>> v(n);
        REP(i, n) cin >> v[i].first >> v[i].second;
        auto x = solve2(v), xx=solve3(v), y = brute(v);
        deb(x, xx);
        REP(i, n) x[i] = min(x[i], xx[i]);
        if (x != y){
            deb(v);
            deb(x, y);
            break;
        }
    }
}
