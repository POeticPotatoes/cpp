#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

const long long M = 1e9;

long long brute(int n, int k, vector<long long> &A) {
    long long ans = -1e18;
    for (int i=1;i<=n;i++) {
        long long cur = 0;
        for (int j=i;j<=min(n, i+k-1);j++) 
            cur += A[j], ans = max(ans, cur);
    }
    return ans;
}

long long solve(int n, int k, vector<long long> &A) {
    vector<long long> S(n+1);
    for (int i=1;i<=n;i++) S[i] = S[i-1]+A[i];

    multiset<long long, greater<long long>> V;
    long long ans = *max_element(&A[1], &A[n]);

    for (int i=0;i<k;i++) V.insert(S[i]);
    for (int i=0;i<n;i++) {
        if (i+k<=n) V.insert(S[i+k]);
        V.erase(V.find(S[i]));
        ans = max(ans, *V.begin() - S[i]);
    }
    return ans;
}

bool test() {
    int n = 20;
    int k = (rng()%n) + 1;
    vector<long long> A(n+1);
    for (int i=1;i<=n;i++) A[i] = (rng() % (2*M))-M;
    long long ans = brute(n, k, A);
    long long res = solve(n, k, A);
    
    if (ans != res) {
        deb(n, k, A);
        deb(ans, res);
        return false;
    }
    return true;
}

int main() {
    int t=1;
    // cin >> t;
    // while (t--) solve();
    for (int i=0;i<1e6;i++) {
        if (!test()) {
            cout<<"Uh oh error\n";
            break;
        }
    }
    cout<<"done!\n";
}
