#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int fact(int n);
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

long long answers[60];
 
// Returns factorial of n
int fact(int n)
{
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    answers[1] = 1;
    answers[2] = 3;

    for (int i=3;i<60;i++) {
        if (i%2) {
            
            continue;
        }
    }

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
    }
}
