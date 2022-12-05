#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i) 
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back

using namespace std;

string s[5005];
int n,Len;
vector<string> vec[5005];
int t[5005],from[5005],b[5005];
int a[5005];
int mov[5005][5005];
int dp[5005];
inline bool check(int maximum,bool visual) {
  For(i,0,Len)	dp[i]=0;
  For(i,0,Len) {
    For(k,1,Len-i) {
      int pos=min(dp[i]+maximum,mov[dp[i]+1][k-1]);
      if(pos>dp[i+k]) {
	dp[i+k]=pos;
	from[i+k]=i;
      }
    }
  } 
  if(!visual)	{
    For(i,0,Len)	
      if(dp[i]==n)	return true;
    return false;
  }

  int col=0;
  int start=0;
  Dow(i,0,Len)	if(dp[i]==n) {start=i;}
  while(start) {
    b[++col]=start-from[start];
    start=from[start];
  }

  printf("%d %d\n",maximum,col);
  reverse(b+1,b+col+1);
  For(i,1,col)	printf("%d ",b[i]-1);
  puts("");
  int now=0,las=1;
  For(i,1,col) {
    now+=b[i];
    For(j,las,dp[now])
      vec[i].pb(s[j]);
    las=dp[now]+1;
  }
  int line=0;
  For(i,1,col)	line=max(line,(int)vec[i].size());

  For(j,0,line-1){
    For(i,1,col) {
      int tlen=0;
      if(vec[i].size()>j)	cout<<vec[i][j],tlen=vec[i][j].length();
      For(k,1,b[i]-tlen)	putchar(' ');	
    }
    puts("");
  }
}
inline void Pre() {
  For(i,1,n) {
    int point=i-1;
    For(j,1,Len) {
      while(point+1<=n&&a[point+1]<=j)
	point++;
      mov[i][j]=point;
    }
  }
}
int main(){
  scanf("%d%d",&n,&Len);
  Len++;
  For(i,1,n) {
    cin>>s[i];
    a[i]=s[i].length();
  }
  Pre();
  int l=1,r=n,ans=0;
  while(l<=r) {
    int mid=(l+r)>>1;
    if(check(mid,0))	ans=mid,r=mid-1;else l=mid+1;
  }
  check(ans,1);
  return 0;
}
