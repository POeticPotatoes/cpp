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
const int maxn = 2e5 + 5;
int n, m;
int z[maxn];

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
  bool operator < (const point &b) const {
    return x == b.x ? y < b.y : x < b.x;
  }
}p[maxn], q[maxn];

int convex(point *p, int n, point *q){
  sort(p + 1, p + n + 1);
  int m = 0;
  for(int i = 1; i <= n; ++ i){
    while(m > 1 && ((q[m - 1] - q[m - 2]) ^ (p[i] - q[m - 2])) <= 0) m --;
    q[m ++] = p[i];
  }
  int k = m;
  for(int i = n - 1; i >= 1; -- i){
    while(m > k && ((q[m - 1] - q[m - 2]) ^ (p[i] - q[m - 2])) <= 0) m --;
    q[m ++] = p[i];
  }
  return m;
}

int main(){
  rd(n);
  rep(i, 1, n) rd(p[i].x), rd(p[i].y);
  if(n == 1){
    puts("4");
    return 0;
  }
  m = convex(p, n, q);
  if(m == 3){
    if(abs(q[0].x - q[1].x) == abs(q[0].y - q[1].y)){
      printf("%d\n", abs(q[0].x - q[1].x) * 2 + 5);
    }
    else printf("%d\n", max(abs(q[0].x - q[1].x), abs(q[0].y - q[1].y)) * 2 + 4);
  }
  else{
    ll ans = 0;
    rep(i, 0, m - 1) p[i] = q[i];
    rep(i, 0, m - 2){
      // printf("(%d, %d)\n", p[i].x, p[i].y);
      int j = i + 1;
      ans += max(abs(p[j].x - p[i].x), abs(p[j].y - p[i].y)) + 1;
      if(p[j].x > p[i].x && p[j].y <= p[i].y) z[i] = 0;
      if(p[j].x <= p[i].x && p[j].y < p[i].y) z[i] = 1;
      if(p[j].x < p[i].x && p[j].y >= p[i].y) z[i] = 2;
      if(p[j].x >= p[i].x && p[j].y > p[i].y) z[i] = 3;
    }
    // printf("ans:%d\n", ans);
    m --;
    rep(i, 0, m - 1){
      int j = (i + 1) % m;
      if((z[i] + 1) % 4 == z[j]) continue;
      if(z[i] == z[j]) ans --;
      if((z[i] + 2) % 4 == z[j]) ans ++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
