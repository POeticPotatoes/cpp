#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

int gOptions[] = {1,0,2,1,2},
    bOptions[] = {0,1,0,1,1};

ll dfs(vector<ll> &q, ll start, ll ans, ll h, int g, int b) {
    const int n = q.size();
    for (;start<n&&h>q[start];start++,ans++) {
        h+=q[start]/2;
    }
    if (start==n) return ans;
    ll m = ans;
    for (int i=0;i<5;i++) {
        if (g<gOptions[i]||b<bOptions[i]) continue;
        ll result = h*pow(2,gOptions[i])*pow(3,bOptions[i]);
        if (result<=q[start]) continue;
        m = max(m, dfs(q,start,ans,result,g-gOptions[i],b-bOptions[i]));
    }
    return m;
}

void solve() {
    ll n, h;
    cin >> n >> h;
    vector<ll> q(n);
    for (int i=0;i<n;i++)
        cin>>q[i];
    sort(q.begin(), q.end());

    cout<<dfs(q,0,0,h,2,1)<<endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
