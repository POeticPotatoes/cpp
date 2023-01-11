#include <bits/stdc++.h>
using namespace std;

#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll i = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll i = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 1, n)
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

struct Item;

vector<Item> A;
um<ll,ll> inv;

struct Item {
    int id;
    bool vis, uncraftable, raw;
    vll items;
    um<ll,ll> mats;

    um<ll,ll> &getItems() {
        if (raw) {
            mats[id] = 1;
            return mats;
        }
        if (vis) return mats;
        vis = 1;
        for (auto i: items) {
            auto m = A[i].getItems();
            if (A[i].uncraftable) {
                uncraftable = 1;
                return mats;
            }
            for (auto j: m) {
                mats[j.first]+=j.second;
                if (mats[j.first] > inv[j.first]) {
                    uncraftable = 1;
                    return mats;
                }
            }
        }
        return mats;
    }
};

ll n, m, c, k;
int ans;

int main() {
    IO;
    cin>>n>>m;
    A = vector<Item>(m+1);
    REP(i, m) A[i].id = i;
    REP(i, n) {
        cin>>c;
        REP(j, c) {
            cin>>k;
            A[i].items.eb(k);
        }
    }
    FOR(i, n+1, m) {
        cin>>c;
        if (!c) {
            A[i].raw = 1;
            cin>>k;
            inv[i]=k;
            continue;
        }
        REP(j, c) {
            cin>>k;
            A[i].items.eb(k);
        }
    }

    REP(i, n) A[i].getItems();
    ans = 0;
    vll craft;
    REP(i, n) if (!A[i].uncraftable) craft.eb(i);
    ll high = pow(2, craft.size())-1;
    REP(i, high) {
        um<ll, ll> req;
        REP(j, craft.size()) {
            if (!(i&(1<<(j-1)))) continue;
            for (auto x: A[craft[j-1]].getItems()) req[x.first]+=x.second;
        }
        bool flag = 0;
        for (auto x: req) {
            if (inv[x.first]<x.second) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        ans = max(ans, __builtin_popcount(i));
    }
    cout<<ans<<endl;
}
