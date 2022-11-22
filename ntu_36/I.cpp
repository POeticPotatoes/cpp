#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long _;
    cin >> _;
    while (_--) {
        long long n, c, t=0, a=0;
        cin >> n;
        vector<long long> nums(n);
        for (long long i=1;i<n;i++) {
            cin >> c;
            t += c;
            nums[i] = t;
        }

        cout << 0;
        t=0;
        for (long long o=0;o<(n-1)/2;o++) {
            t += nums[n-1-o]-nums[o];
            a += t;
            cout << " " << a;
            a += t;
            cout << " " << a;
        }

        if (!(n&1)) {
            t += nums[n/2]-nums[(n-2)/2];
            a += t;
            cout << " " << a;
        }

        cout << endl;
    }
}
