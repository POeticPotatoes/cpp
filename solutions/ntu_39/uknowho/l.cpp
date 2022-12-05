#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i) 
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back

using namespace std;

double ksm(double x,int y){double ret=1;for(;y;y/=2,x=x*x) if(y&1)	ret=ret*x;return ret;}

int n,pos,k;
double ans;
double p[1000005];
int main() {
  scanf("%d%d%d",&n,&pos,&k);
  For(i,1,n) 
    p[i]=ksm(1.0*(i)/n,k);
  Dow(i,1,n)	p[i]-=p[i-1];
  For(i,1,n) {
    if(i<pos)	ans+=p[i]*pos;
    else ans+=p[i]*(i+1)/2;
    //		cout<<p[i]<<' '<<i<<endl;
  }
  printf("%.20lf",ans);
}
