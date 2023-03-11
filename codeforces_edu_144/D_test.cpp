#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T,typename ...U> void _do(T x,U ...y){cerr<<x<<", ";_do(y...);}
#define dbg(...) cerr<<#__VA_ARGS__<<" = ";_do(__VA_ARGS__);

const int MOD1=1e9+7;
const int MOD2=998244353;
const ll INF=3e18;

ll fpow(ll a,ll b,ll m)
{
    if(!b) return 1;
    ll tmp=1;
    for(ll cur=a;b;b>>=1,cur=cur*cur%m) if(b&1) tmp=tmp*cur%m;
    return tmp;
}
ll inv(ll a,ll m) {return fpow(a,m-2,m);}

#define MottoHayaku ios::sync_with_stdio(false);cin.tie(0);
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define F first
#define S second
#define pb push_back
#define uni(c) c.resize(distance(c.begin(),unique(c.begin(),c.end())))
#define unisort(c) sort(c.begin(),c.end()),uni(c)

const int N=2e5+5;
ll a[N],sum[N],mn[N];
void solve()
{
    ll n,k,x;
    cin>>n>>k>>x;
    if(x<0)
    {
        x=-x;
        k=n-k;
    }
    rep1(i,n)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        mn[i]=min(mn[i-1],sum[i]-x*i);
    }
    multiset<ll> s;
    s.insert(0);
    ll ans=0;
    rep1(i,n)
    {
        if(i-k-1>=0)
        {
            s.erase(s.find(sum[i-k-1]+x*(i-k-1)));
        }
        s.insert(sum[i]+x*i);
        ans=max(ans,sum[i]+x*i-(*s.begin()));
        if(i-k<=0 || mn[i-k-1]>0) continue;
        ans=max(ans,sum[i]-x*i-mn[i-k-1]+x*k*2);
    }
    cout<<ans<<"\n";
}

signed main()
{
    MottoHayaku

    int t;
    cin>>t;
    //t=1;
    while(t--)
    {
        solve();
    }
}
