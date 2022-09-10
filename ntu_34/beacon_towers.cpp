#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m=0, i;
    long long ans=1, c=0;
    cin >> n;

    cin >> m;
    n--;
    while (n--) {
        c++;
        cin >> i;
        if (i >= m) {
            ans += ans*c%1000000007ll;
            c = 0;
            m = i;
        }
    }

    cout << ans%1000000007ll << endl;
}
