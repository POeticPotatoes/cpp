#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n == k) {
        cout << "No" << endl;
        return 0;
    }

    /* For each n where there is an answer,
     * there exists an answer which consists of unique primes
     *
     * It is therefore possible to implement some sort of 
     * sieve of Erasthotenes to identify primes within the range of n
     * and identify combinations that sum up to n.
     *
     * However, the problem of subsets within the found primes
     * still exists: eg. 14 = 7 + 2 + 5*/
}
