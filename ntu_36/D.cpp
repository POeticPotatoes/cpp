#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define M_PI 3.14159265358979323846264338327
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double a, b, r, d;
        cin >> a >> b >> r >> d;
        d *= M_PI/180;
        double l = sqrt((a+r)*(a+r)+b*b),
               x = atan(b/(a+r));
        if (x <= d)
            printf("%.12f\n", l-r);
        else {
            double y = l-r/cos(x-d);
            printf("%.12f\n", cos(x-d)*y);
        }
    }
}
