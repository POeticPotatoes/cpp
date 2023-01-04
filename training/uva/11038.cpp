#include <bits/stdc++.h>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
const int N = 10;

ll s[N], *v, n, d, x, ans, k, m, l, a, b;

ll mult(ll val) {
    k = 0;
    do {
        val -= l*d;
        l /= 10, d = val/l, x--;
        if (!d) {
            k += val+1;
            continue;
        }
        k += l + d*l*x/10;
    } while (l>1);
    return k;
}

ll count_zeroes(ll val) {
    if (val<0) return 0;
    if (val<10) return 1;
    x = log10(val), l = pow(10, x), d = val/l,
       ans = s[x] + x*(d-1)*l/10;
    ans += mult(val);
    return ans;
}

void solve() {
    cout<<count_zeroes(b)-count_zeroes(a-1)<<endl;
}

int main() {
    IO;
    v = s+1;
    s[0] = 0;
    v[0] = 1;
    FOR(i, 1, N-1) {
        v[i] = v[i-1];
        v[i] += i*(9*pow(10, i-1));
    }
    while (true) {
        cin>>a>>b;
        if (a<0) break;
        solve();
    }
    /*while (true) {
        cin>>n;
        cout<<count_zeroes(n)<<endl;
    }*/
}
