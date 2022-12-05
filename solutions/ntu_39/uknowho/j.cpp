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

typedef pair <int, int> pr;
const int maxn = 1005;
int x[maxn], y[maxn];
vector <pr> p;

int main(){
  int n; rd(n);
  rep(i, 0, n - 1){
    rd(x[i]), rd(y[i]);
  }
  bool flag = false;
  rep(i, 0, n - 1){
    int j = (i + 1) % n;
    int t = abs(y[i] - y[j]);
    if(t == 180){ flag = true; break; }
    int a = y[i], b = y[j];
    if(a > b) swap(a, b);
    if(a == b) continue;
    if(t < 180) p.push_back(pr(a, b));
    else p.push_back(pr(-180, a)), p.push_back(pr(b, 180));
  }
  if(flag){
    puts("yes");
  }
  else{
    flag = true;
    sort(p.begin(), p.end());
    int lst = -180;
    for(int i = 0; i < p.size(); ++ i){
      // printf("[%d, %d]\n", p[i].first, p[i].second);
      if(p[i].first > lst){
	flag = false;
	printf("no %.1lf\n", (double) lst + 0.5);
	break;
      }
      else lst = max(lst, p[i].second);
    }
    if(flag){
      if(lst != 180) printf("no 179.5");
      else puts("yes");
    }
  }
  return 0;
}
