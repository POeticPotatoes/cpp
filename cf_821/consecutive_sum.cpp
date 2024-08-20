#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, a, nums[100]{};
        cin >> n >> k;
        
        for (int i=0; i<n; i++) {
            cin >> a;
            int m = i%k;
            nums[m] = max(nums[m], a);
        }

        long long ans = 0;
        for (int i=0; i<k; i++) {
            ans += nums[i];
        }
        cout << ans << endl;
    }
}
