#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll n, p, ne, ans = 0, cur=1;
    cin >> n>>p;
    ne = n-1-!(n&1);
    ll start = (ne)/2;
    for (int i=1;i<start;i++)
        cur = (cur * i)%p;
    for (int i=start;i<=ne;i++) {
        cur = (cur * i)%p;
        ans = (ans + cur)%p;
    }
    ans--;
    cout << ((2*(n*ans)%p)%p)%p << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
