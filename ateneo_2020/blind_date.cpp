#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

long long m = 180758,
    mod = 104206969;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;
    a--;

    long long l1 = a/4ll - a/100ll + a/400ll + (a >= 0);
    long long l2 = b/4ll - b/100ll + b/400ll + (b >= 0);

    cout << ((b-a)%mod*m + (l2-l1)*229ll)%mod<< endl;
}
