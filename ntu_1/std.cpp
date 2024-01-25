//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define mp make_pair
#define pb push_back
#define MAXN 510
typedef long long ll;
int n, m;
int nxt[MAXN][2], f[MAXN][MAXN][MAXN];
char s[MAXN], t[MAXN];

int main()
{
	memset(f, 0xff, sizeof(f));
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	scanf("%s", t+1);
	t[m+1] = '#';
	rep(i, 0, m)
		rep(j, 0, 1)
		{
			for(int k = i + 1; k >= 0; k--)
			{
				bool flag = true;

				rep(offset, 1, k - 1)
				{
					if(t[offset] != t[i + 1 - k + offset])
						flag = false;
				}
				
				if(t[k] != '0' + j) flag = false;
				if(flag)
				{
					nxt[i][j] = k;
					break;
				}
			}
		}
		
	f[0][0][0] = 0;
    for (int i=0;i<m;i++) { cout<<nxt[i][(t[i+1]-'0')^1]<<" "; }
    cout<<endl;
    cout<<"RES\n";
		
	rep(i, 0, n - 1)
		rep(j, 0, m)
			rep(k, 0, n - m + 1)
			{
				if(f[i][j][k] == -1) continue;
				rep(x, 0, 1)
				{
					int matched = 0, cost = 0;
					if(nxt[j][x] == m) matched = 1;
					if(s[i + 1] != x + '0') cost = 1;
					if(f[i + 1][nxt[j][x]][k + matched] == -1)
						f[i + 1][nxt[j][x]][k + matched] = f[i][j][k] + cost;
					else
						f[i + 1][nxt[j][x]][k + matched] = min(f[i + 1][nxt[j][x]][k + matched], f[i][j][k] + cost);
				}
			}
			
	rep(i, 0, n - m + 1)
	{
		int ans = -1;
		rep(j, 0, m)
		{
			if(ans == -1) ans = f[n][j][i];
			else
			{
				if(f[n][j][i] != -1) ans = min(ans, f[n][j][i]);
			}
		}
		printf("%d%c", ans, (i == n-m+1)?'\n':' ');
	}
	return 0;
}
