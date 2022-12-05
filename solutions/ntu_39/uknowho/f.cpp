#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = (b); a <= (c); ++ a)
#define per(a, b, c) for(int a = (b); a >= (c); -- a)
using namespace std;
template <class T> void rd(T &x){
  x = 0; int f = 1; char ch = getchar();
  while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
  while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}

typedef long long ll;
const int maxn = 1e5 + 5;
int n;
vector <ll> g;
ll ans;

struct point{
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  point operator - (const point &b) const {
    return point(x - b.x, y - b.y);
  }
  ll operator * (const point &b) const {
    return x * b.x + y * b.y;
  }
  ll operator ^ (const point &b) const {
    return x * b.y - y * b.x;
  }
}s, e, p[maxn];

struct binary_indexed_tree{
  int c[maxn];

  void add(int x){
    for(; x <= n; x += x & -x)
      c[x] ++;
  }

  int query(int x){
    int res = 0;
    for(; x; x -= x & -x)
      res += c[x];
    return res;
  }
}bit[2];

typedef pair <point, point> prp;
vector <prp> pp[2];
typedef pair <point, int> pr;
pr b[maxn];
int idx[maxn];

bool cmp1(prp a, prp b){
  return (b.first ^ a.first) == 0 ? (b.second ^ a.second) < 0 : (a.first ^ b.first) < 0;
}

bool cmp(pr a, pr b){
  return (b.first ^ a.first) < 0;
}

void solve(int id){
  if(pp[id].size() == 0) return ;
  int cnt = pp[id].size();
  sort(pp[id].begin(), pp[id].end(), cmp1);
  rep(i, 0, cnt - 1){
    b[i] = pr(pp[id][i].second, i);
  }
  sort(b, b + cnt, cmp);
  int tot = 0;
  idx[b[0].second] = ++ tot;
  rep(i, 1, cnt - 1){
    if((b[i].first ^ b[i - 1].first) == 0) idx[b[i].second] = tot;
    else idx[b[i].second] = ++ tot;
  }
  rep(i, 0, cnt - 1){
    int t = idx[i];
    ans += bit[id].query(t);
    bit[id].add(t);
  }
}

int main(){
  rd(s.x), rd(s.y), rd(e.x), rd(e.y);
  rd(n);
  rep(i, 1, n) rd(p[i].x), rd(p[i].y);
  rep(i, 1, n){
    ll t = ((p[i] - s) ^ (e - s));
    if(t == 0){
      g.push_back((p[i] - s) * (e - s));
    } else if(t < 0){
      pp[0].push_back(prp(p[i] - s, p[i] - e));
    } else{
      pp[1].push_back(prp(p[i] - e, p[i] - s));
    }
  }
  if(g.size()){
    int tot = g.size();
    int cnt = 0;
    rep(i, 0, tot - 1) if(g[i] < 0) cnt ++;
    if(cnt) ans += (ll) cnt * (cnt - 1) / 2;
    cnt = tot - cnt;
    if(cnt) ans += (ll) cnt * (cnt - 1) / 2;
  }
  rep(i, 0, 1) solve(i);
  printf("%lld\n", ans);
  return 0;
}
