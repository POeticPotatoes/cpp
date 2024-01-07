#include <cstdio>
#include <cmath>
#include <algorithm>

const int N = 1e6 + 50;
const int MAX_DIVISORS = N * 10; // This is an arbitrary large value to make sure we can store all divisors.

long long x[N], a[N];
long long divisors[MAX_DIVISORS];
int divisorsCount = 0;

void divide(long long x) {
    for (long long i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            divisors[divisorsCount++] = i;
            if (i != x / i) {
                divisors[divisorsCount++] = x / i;
            }
        }
    }
}

bool check(int d) {
    int s[MAX_DIVISORS];
    for (int i = 0; i < d; i++) {
        s[i] = -1;
    }
    int filled = 0;
    for (int i = 1; i <= d; ++i) {
        int y = (x[i] % d + d) % d;
        if (s[y] == -1) {
            s[y] = a[i];
            ++filled;
        } else if (s[y] != a[i]) {
            return true;
        }
    }
    if (filled != d) return false;
    for (int t = 1; t < d; ++t) {
        bool ok = true;
        for (int i = 0; i < d; ++i) {
            if (s[i] != s[(i + t) % d]) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    long long n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld", &x[i], &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (a[i] != a[j]) {
                long long t = std::abs(x[i] - x[j]);
                divide(t);
            }
        }
    }
    for (int d = 1; d <= 50; ++d) {
        if (check(d)) {
            divisors[divisorsCount++] = d;
        }
    }
    std::sort(divisors, divisors + divisorsCount);
    int uniqueCount = std::unique(divisors, divisors + divisorsCount) - divisors;
    long long sum = 0;
    for (int i = 0; i < uniqueCount; ++i) {
        sum += divisors[i];
    }
    printf("%d %lld\n", uniqueCount, sum);
    return 0;
}
