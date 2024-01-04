#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
typedef long long ll;

const ll N = 2e5;
const ll INF = 1e18;

ll n, x, y;
pair<ll, ll> A[N];
vector<ll> st[N<<1]; 

vector<ll> &buildTree(ll p, ll l, ll r) {
    if (l == r) {
        st[p].push_back(A[l].second);
        return st[p];
    }
    ll m = (l+r)>>1;
    auto &a = buildTree(p<<1, l, m),
         &b = buildTree((p<<1)+1, m+1, r);

    // 2-pointer algorithm (merging sorted lists)
    auto ptr = b.begin();
    for (auto v: a) {
        while (ptr != b.end() && *ptr<v)
            st[p].push_back(*ptr++);
        st[p].push_back(v);
        if (ptr == b.end()) break;
    }
    while (ptr != b.end()) st[p].push_back(*ptr++);

    return st[p];
}

ll query(ll a, ll b, ll v, ll p, ll l, ll r) {
    if (b<l || a>r) return 0;
    if (a<=l && b>=r) {
        return upper_bound(st[p].begin(), st[p].end(), v) - st[p].begin();
    }
    ll m = (l+r)>>1;
    return query(a, b, v, p<<1, l, m) + query(a, b, v, (p<<1)+1, m+1, r);
}

void solve() {
    cin>>n>>x>>y;
    for(int i=0;i<n;i++) cin>>A[i].first;
    for(int i=0;i<n;i++) cin>>A[i].second;
    sort(A, A+n);

    buildTree(1, 0, n-1);

    for(int i=0;i<n;i++) {
        ll b = (upper_bound(A, A+n, make_pair(x-A[i].first, INF)) - A);
        ll res = query(0, b-1, y-A[i].second, 1, 0, n-1);
        printf("%lld pairs match {%lld, %lld}\n", res, A[i].first, A[i].second);
    }
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
