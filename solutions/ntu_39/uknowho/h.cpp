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
const int maxn = 5e5 + 5;
int n;
ll a[maxn], b[maxn];

int cmp(int x, int y){ return a[x] >= a[y] ? x : y; }

struct segment_tree{
  int mx[maxn << 2];

#define lson u << 1, l, mid
#define rson u << 1 | 1, mid + 1, r

  void build(int u, int l, int r){
    if(l == r) return (void) (mx[u] = l);
    int mid = l + r >> 1;
    build(lson), build(rson);
    mx[u] = cmp(mx[u << 1], mx[u << 1 | 1]);
  }

  int query(int u, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return mx[u];
    int mid = l + r >> 1, res = -1;
    if(ql <= mid) res = query(lson, ql, qr);
    if(qr > mid){
      if(res == -1) res = query(rson, ql, qr);
      else res = cmp(res, query(rson, ql, qr));
    }
    return res;
  }
}seg;

int pre(int x){ return (x - 1 + n) % n; }
int suf(int x){ return (x + 1) % n; }

ll sum(int l, int r){
  if(l == suf(r)) return 0;
  else{
    if(l <= r) return b[r] - b[l] + a[l];
    else return b[r] + b[n - 1] - b[l] + a[l];
  }
}

ll solve(int l, int r, ll mx){
  // printf("[%d, %d] mx:%lld\n", l, r, mx);
  if(l == suf(r)) return mx;
  if(l == r){
    if(a[l] * 2 >= mx) return a[l];
    else return mx - a[l];
  }
  int p;
  if(l < r){
    p = seg.query(1, 0, n - 1, l, r);
  }
  else{
    p = cmp(seg.query(1, 0, n - 1, l, n - 1), seg.query(1, 0, n - 1, 0, r));
  }
  if(a[p] * 2 >= mx){
    return min(solve(l, pre(p), a[p]), solve(suf(p), r, a[p]));
  }
  else{
    return min(solve(l, pre(p), max(mx - sum(p, r), a[p])), 
	solve(suf(p), r, max(mx - sum(l, p), a[p])));
  }
}

int main(){
  rd(n);
  rep(i, 0, n - 1) rd(a[i]);
  b[0] = a[0];
  rep(i, 1, n - 1) b[i] = b[i - 1] + a[i];
  // printf("sum:%lld\n", sum(2, 0));
  seg.build(1, 0, n - 1);
  int p = seg.query(1, 0, n - 1, 0, n - 1);
  printf("%lld\n", solve(suf(p), pre(p), a[p]));
  return 0;
}
