#include <bits/stdc++.h>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) < (b); (i)++)
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

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;

int n;

void case2(vector<int> &a) {
    cout<<((a[1] == 2)?"Impossible":"Possible\n2 1\n2 1")<<endl;
}

void case3(vector<int> &a) {
    int sum = (a[1]==1) + (a[2] == 2) + (a[3] == 3);
    if (sum == 1) {
        cout<<"Impossible"<<endl;
        return;
    }
    cout<<"Possible"<<endl;
    if (sum == 3) {
        cout<<"2 3 1\n3 1 2\n";
        return;
    }
    if (a[1] == 2) {
        cout<<"2 3 1\n2 3 1\n";
        return;
    }
    cout<<"3 1 2\n3 1 2\n";
}

int g(int a) { return (a+n-1)%n+1; }

void solve() {
    cin>> n;
    vector<int> a(n+1), m(n+1), rot(n+1);
    um<int, int> mapping, dirty;

    FOR(i, 1, n+1) {
        cin>>a[i];
        dirty[a[i]] = i;
        rot[g(i-a[i])]++;
    }
    if (n==1) return (void) (cout<<"Impossible"<<endl);
    if (n==2) return (void) case2(a);
    if (n==3) return (void) case3(a);

    rot[0] = n;
    int r=0;
    FOR(i, 1, n) if (rot[i]<rot[r]) r=i;

    iota(m.begin()+r+1, m.end(), 1);
    iota(m.begin(), m.begin()+r+1, n-r);
    // FOR(i, 1, n)
    //     cout<<" "<<rot[i];
    // cout<<endl;
    // cout<<"rot: "<<r<<endl;
    // FOR(i, 1, n+1)
    //     cout<<", "<<m[i];
    // cout<<endl;

    FOR(i, 1, n+1) {
        if (m[i] == a[i] || m[i] == i) {
            int j=g(i+1);
            for(;m[j]==i||j==m[i];j=g(j+1));
            swap(m[i], m[j]);
        }
        mapping[m[i]] = i;
    }

    // FOR(i, 1, n+1)
    //     cout<<" "<<m[i];
    // cout<<endl;

    // Print output
    cout<<"Possible\n"<<dirty[m[1]];
    FOR(i, 2, n+1)
        cout<<" "<<dirty[m[i]];
    cout<<endl;
    
    cout<<mapping[1];
    FOR(i, 2, n+1)
        cout<<" "<<mapping[i];
    cout<<endl;
}

int main() {
    IO;
    int t=1;
    cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
