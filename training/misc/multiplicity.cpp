#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

long nums[100000], sums[100000]{}, d, c=0;
int n;

int main() {
    long a;
    cin >> n;
    
    for (int i=0;i<n;i++) {
        cin >> a;
        nums[i] = a;
    }

    sums[0] = 1;

    for (int i=1;i<n;i++) {
        long x = nums[i];
        for (int m=i+1;m>1;m--) {
            d = sums[m-2];
            if (d && !(x%m))
                sums[m-1] += sums[m-2];
        }
        sums[0]++;
    }

    for (int i=0;i<n;i++)
        c += sums[i];
    
    cout << c << endl;
}
