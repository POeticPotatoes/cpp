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
constexpr int N = 2e5+1;

int n, flag, A[N], B[N], C[N];

void solve() {
    flag = 0;
    stack<int> bf, cf;
    cin>>n;
    vv<int> used(n+1);
    REP(i, n) {
        cin>>A[i];
        used[A[i]].eb(i);
        flag += (used[A[i]].size()>2);
    }
    if (flag) return (void) (cout<<"NO"<<endl);

    ROF(i, n, 0) {
        if (used[i].size() == 2) {
            B[used[i][0]] = i;
            cf.push(used[i][0]);

            C[used[i][1]] = i;
            bf.push(used[i][1]);
            continue;
        }
        if (used[i].size()) {
            B[used[i][0]] = i;
            C[used[i][0]] = i;
            continue;
        }
        if (cf.empty() || bf.empty())
            return (void) (cout<<"NO"<<endl);
        B[bf.top()] = i; bf.pop();
        C[cf.top()] = i; cf.pop();
    }

    cout<<"YES"<<endl;
    REP(i, n) cout<<B[i]<<" ";
    cout<<endl;
    REP(i, n) cout<<C[i]<<" ";
    cout<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
