#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
typedef long long ll;

const int N=1e5;

ll n, m;
vector<int> A[N+1][2];

void solve() {
    cin>>n>>m;

    int c;
    for(int i=0;i<n;i++)
        for (int j=0;j<m;j++) {
            cin>>c;
            A[c][0].emplace_back(i);
            A[c][1].emplace_back(j);
        }

    ll ans = 0;
    for(int i=0;i<=N;i++) {
        if (A[i][0].empty()) continue;
        auto &v = A[i][0];
        ll l = 0, inc=0;
        for (int j=1;j<v.size();j++) {
            if (v[j] != v[j-1])
                l = j-1, inc+=(l+1) * (v[j]-v[j-1]);
            ans += inc;
        }
        deb(i, v, ans);
    }

    for(int i=0;i<=N;i++) {
        if (A[i][1].empty()) continue;
        auto &v = A[i][1];
        sort(v.begin(), v.end());
        ll l = 0, inc=0;
        for (int j=1;j<v.size();j++) {
            if (v[j] != v[j-1])
                l = j-1, inc+=(l+1) * (v[j]-v[j-1]);
            ans += inc;
        }
        deb(i, v, ans, 2);
    }

    cout<<ans<<endl;
}

int main() {
    int t=1;
    // cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
