#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, r, c, x, ans=0;
    cin >> n >> k >> r;
    vector<bool> houses(n);

    while (k--) {
        cin >> x;
        houses[x-1] = true;
    }

    c = 0;
    for (int i=0;i<r;i++)
        c += houses[i];
    if (c < 2) {
        if (!c || houses[r-1]) houses[r-2] = true;
        houses[r-1] = true;
        ans += 2-c;
        c = 2;
    }

    for (int i=r;i<n;i++) {
        c -= houses[i-r];
        c += houses[i];
        if (c < 2) {
            houses[i] = 1;
            ans++;
            c++;
        }
    }
    
    cout << ans << endl;
}
