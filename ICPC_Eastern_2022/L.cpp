#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define int long long
#define print(a) for(auto x : a) cout << x << ' '; cout << endl
#define forn(n) for(int i=0; i<n; i++)
#define fornn(n) for(int j=0; j<n; j++)

struct A {
public:
  bool bw;
  int abs;
  int ind;
  int row;
  int val;
};

void solve() {
  int a[98];
  set<pair<int, int>> st;
  forn(98) {
    cin >> a[i];
  }

  vector<int> a1, a2, d1, d2;
  a1.push_back(1);
  a2.push_back(1);
  d1.push_back(100);
  d2.push_back(100);

  forn(8) st.insert({i, a[i]});
  int p = 8;

  while(st.size()){
    bool flag=0;
    for(int _=0; _<2; _++){
      vector<A> moves;
      for (auto [i, x]: st) {
        if (x < a1.back()) {
          if (a1.back() - x == 10) moves.push_back(A{true, 10, i, 1, x});
        }
        else moves.push_back(A{false, x-a1.back(), i, 1, x});
        if (x < a2.back()) {
          if (a2.back() - x == 10) moves.push_back(A{true, 10, i, 2, x});
        }
        else moves.push_back(A{false, x-a2.back(), i, 2, x});
        if (x > d1.back()) {
          if (x - d1.back() == 10) moves.push_back(A{true, 10, i, 3, x});
        }
        else moves.push_back(A{false, d1.back()-x, i, 3, x});
        if (x > d2.back()) {
          if (x - d2.back() == 10) moves.push_back(A{true, 10, i, 4, x});
        }
        else moves.push_back(A{false, d2.back()-x, i, 4, x});
      }

      if (moves.empty()) {
          flag=1;
        break;
      }

      sort(moves.begin(), moves.end(), [&] (A x, A y){
        if (x.bw && y.bw) {
          if (x.ind == y.ind) {
            return x.row < y.row;
          }
          else return x.ind < y.ind;
        }
        else if (x.bw){
          return true;
        }
        else if (y.bw) {
          return false;
        }
        else {
          if (x.abs == y.abs) {
            if (x.ind == y.ind){
              return x.row < y.row;
            }
            else return x.ind < y.ind;

          }
          else return x.abs < y.abs;
        }
      });

      A move = moves.front();

      switch (move.row) {
        case 1:
          a1.push_back(move.val);
          break;
        case 2:
          a2.push_back(move.val);
          break;
        case 3:
          d1.push_back(move.val);
          break;
        case 4:
          d2.push_back(move.val);
          break;
        default:
          break;
      }

      st.erase({move.ind, move.val});
    }
    if (flag) break;
    if (p<98) {
      st.insert({p, a[p]});
      p++;
    }
    if (p<98) {
      st.insert({p, a[p]});
      p++;
    }
  }

  print(a1);
  print(a2);
  print(d1);
  print(d2);

  for (auto &[_, b]: st) cout<<b<<" ";
  cout<<"\n";
  while (p<98) cout<<a[p++]<<" ";
  cout<<"\n";
}

int32_t main() {
  int t = 1;
  // cin >> t;
  while (t--) solve();

return 0;
}
