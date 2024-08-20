#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll i = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vv<T>>;
template <typename T, typename N>
using um = unordered_map<T, N>;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

constexpr int M = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

const ll N = 2e5;

string s;
ll n, t, C[26];
char A[N];

void solve() {
    cin>>s;
    n = s.size(), A[n] = 0, t=0;
    memset(C, 0, sizeof(ll)*26);
    for (auto c:s) t += !C[c-'a']++;
    char carry = 0;
    int l=0, r=n-1;
    REP(i, 26) {
        if (!C[i]) continue;
        char c = 'a'+i;
        t--;
        while (C[i]>1) {
            A[l++] = c, A[r--] = c;
            C[i]-=2;
        }
        if (C[i]) {
            carry = c;
            break;
        }
    }
    if (carry) {
        if (t==1) {
            int j;
            for(j=25;!C[j];j--);
            char c = 'a' + j;
            while (l<r) A[l++] = c, A[r--] = c;
            A[l] = carry;
        } else {
            C[carry-'a']--;
            A[r--] = carry;
            ROF(i, 25, -1) while (C[i]--) A[r--] = 'a'+i;
        }
    }
    cout<<A<<endl;
}

int main() {
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
