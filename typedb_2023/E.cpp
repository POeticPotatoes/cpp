#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
typedef long long ll;

const ll N = 3e5;

ll n, k, x, vis[N];

void solve() {
    cin>>n>>k>>x;
    vector<vector<ll>> P;
    vector<ll> E;
    memset(vis+1, 0, sizeof(ll)*n);

    for(int i=1;i<=n;i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        if (i==x && P.size()<k)
            P.push_back({i});
        else if ((x^i) <= n && P.size()<k) {
            P.push_back({i, x^i});
            vis[x^i] = 1;
        } else E.emplace_back(i);
    }
    // deb(P.size(), k, E.empty());
    if (P.size() < k - (!E.empty())) {
        cout<<"NO\n";
        return;
    }
    if (E.size()) {
        ll a = 0;
        for (auto i: E) a^=i;
        // deb(a, P[0], E, P.size(), k);
        if ((P.size()<k && a!=x) || (P.size()==k && a)) {
            cout<<"NO\n";
            return;
        }
        if (P.size() == k)
            P[0].insert(P[0].end(), E.begin(), E.end());
        else P.push_back(E);
    }
    cout<<"YES\n";
    for(const auto &v: P) {
        cout<<v.size();
        for (const auto &j: v) cout<<" "<<j;
        cout<<"\n";
    }
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
