#include<iostream>
#include<bitset>
#include<algorithm>
#include<cassert>
using namespace std;
bitset<2001>Ldp[2001];
bitset<2001>dp[2001];
int N,D;
int L[2000];
int main()
{
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>D;
		for(int i=0;i<N;i++)cin>>L[i];
		sort(L,L+N);
		reverse(L,L+N);
		for(int i=0;i<=N;i++)Ldp[i].reset();
		Ldp[0].set(0);
		int sum=0;
        // knapsack DP
		for(int i=0;i<N;i++)
		{
			sum+=L[i];
			Ldp[i+1]=Ldp[i]|Ldp[i]<<L[i];
		}
		if(sum==D)
		{
			cout<<"Yes\n";
			continue;
		}
        // Otherwise, some item must be excluded from the diameter
        
		for(int d=0;d<=D;d++)dp[d].reset();
		dp[0].set(0);
		bool fn=false;
		for(int i=N;i--;)
		{
			//del L[i]
			sum-=L[i];
			if(sum<=D)
			{
                // If there is some sum x smaller than D which does not include the current i,
				for(int x=0;x<=sum;x++)if(Ldp[i].test(x))
				{
                    // Left bound: Requires a subset of unused items BELONGING to the subset that completes the current sum that makes x larger than or equal to L[i]
                    // Right bound: Requires a subset of unused items BELONGING to the subset that completes the current sum that does not make the remaining sum smaller than L[i]
					int ly=max(L[i]-x,0),ry=D-x-L[i];
					if(ly>ry)continue;

                    cout<<i<<" "<<L[i]<<" "<<x<<" "<<ly<<" "<<ry<<"\n";
                    // Perform the check
					if((dp[D-sum]>>ly<<2000-ry+ly).any())
					{
						fn=true;
						break;
					}
				}
				if(fn)break;
			}
			// DP on subset sums contained in each sum
            // that's crazy
			for(int d=D-L[i];d>=0;d--)
			{
				dp[d+L[i]]|=dp[d]|dp[d]<<L[i];
			}
		}
		cout<<(fn?"Yes\n":"No\n");
	}
}
