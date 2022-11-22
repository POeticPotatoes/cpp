#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n,i,a,j,b, c=0;
        cin >> n >> i >> a >> j >> b;
        for (;j||i;i>>=1,j>>=1) c+=(j&1)^(i&1);
    }
}
