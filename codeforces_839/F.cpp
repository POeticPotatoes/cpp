#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
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

ll n,m,k;

int xc[]{0,0,1,-1}, yc[]{1,-1,0,0};

struct State {
    int index;
    vector<string> board;
    vector<pair<int, int>> available;
};

struct greater_than {
    inline bool operator() (const State a, const State b) { return a.available.size()>b.available.size(); }
};

void update(State &s) {
    FOR(y, 1, n-1) {
        FOR(x, 1, m-1) {
            int sum=0;
            REP(i, 4) sum+=(s.board[y+yc[i]][x+xc[i]])=='0';
            if (!(sum - 4*(s.board[y][x] != '0'))) {
                s.available.eb(pair<int,int>{y,x});
            }
        }
    }
}

void compare(State &a, State &b) {
    REP(y, n) REP(x, m)
        if (a.board[y][x] != b.board[y][x])
            cout<<"1 "<<y+1<<" "<<x+1<<endl;
}

void solve() {
    cin>>n>>m>>k;
    vector<State> states(k+1);
    REP(i, k+1) {
        states[i].index = i+1;
        states[i].board = vector<string>(n);
        REP(j, n) cin>>states[i].board[j];
        update(states[i]);
    }
    sort(all(states), greater_than());
    cout<<states[0].index<<endl;
    
    int diff=k;
    REP(y, n) REP(x, m)
        diff += states[0].board[y][x] != states[k].board[y][x];
    cout<<diff<<endl;

    REP(i, k) {
        compare(states[i], states[i+1]);
        cout<<"2 "<<states[i+1].index<<endl;
    }
}

int main() {
    IO;
    int t=1;
    //cin >> t; // Comment this out if there are no tests
    while (t--) solve();
}
