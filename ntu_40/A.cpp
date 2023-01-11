#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#include <fstream>
#include <unordered_map>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
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
constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
string a, b;

int compare(int p1, int p2, int changes) {
    for (;p1<a.size() && p2<b.size() && a[p1] == b[p2];p1++,p2++);
    if (p1==a.size()) return changes + b.size()-p2;
    if (p2==b.size()) return changes + a.size()-p1;

    // Try all 3;
    int ans = inf;
    if (changes>3) return inf;
    ans = min(ans, compare(p1, p2+1, changes+1));
    ans = min(ans, compare(p1+1, p2, changes+1));
    ans = min(ans, compare(p1+1, p2+1, changes+1));
    return ans;
}

void solve() {
    cin>>a>>b;
    int actions = compare(0,0,0);
    if (actions==0) return (void) (cout<<"You're logged in!"<<endl);
    if (actions==1) return (void) (cout<<"You almost got it. You're wrong in just one spot."<<endl);
    if (actions==2) return (void) (cout<<"You almost got it, but you're wrong in two spots."<<endl);
    if (actions==3) return (void) (cout<<"You're wrong in three spots."<<endl);
    cout<<"What you entered is too different from the real password."<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
