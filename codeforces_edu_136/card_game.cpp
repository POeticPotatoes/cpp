#include <bits/stdc++.h>
using namespace std;

constexpr int m = 998244353;
long long f[31];

long long choose(int a, int b) {
    return f[a]/(f[b]*f[a-b]%m)%m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    f[1] = 1;
    f[2] = 3;
    long long cur = 3, counter=4;
    for (int i=3;i<31;i++) {
        cur = cur*counter*(counter+1)/i/(i-1)%m;
        f[i] = (cur + f[i-1])%m;
        counter += 2;
    }
    for (int i=0; i<31;i++)
        cout << f[i] << endl;

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << f[n/2] << " " << f[n/2-1] << " " << 1 << endl;
    }
}
