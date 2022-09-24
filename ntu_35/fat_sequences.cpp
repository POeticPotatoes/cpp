#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

constexpr array<long, 100000> computeMutes() {
    array<long,100000> result = {};
    long t = 0;
    for (int i=1;i<100000;i++) {
        t = (t + i)%1000000007l;
        result[i] = (result[i-1]+t)%1000000007l;
    }
    return result;
}

constexpr array<long, 100000> computeSums() {
    array<long, 100000> sums = {};
    for (int i = 1;i<50000;i++)
        for (long n=i;n<1000000007l;n+=i)
            sums[n] = ((sums[n]) + 1)%1000000007l;
    return sums;
}

constexpr array<long, 100000> sums = computeSums();
constexpr array<long, 100000> perms = computeMutes();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i=90000; i<90100; i++)
        cout << " " << perms[i];
    cout << endl;

    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;

    }
}
