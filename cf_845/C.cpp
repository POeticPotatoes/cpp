#include </Users/poeticpotato/Desktop/Work/cpp/bits.h>
using namespace std;

#ifdef DEBUG
    #include </Users/poeticpotato/Desktop/Work/cpp/debug.h>
#else
  #define deb(x...)
#endif
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define FORN(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) > (b); (i)--)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vv<T>>;
template <typename T, typename N>
using um = unordered_map<T, N>;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

constexpr int MOD = 1e9+7;
constexpr int inf = (int)1e9;
constexpr ll INF = 1e18;
constexpr ll N = 2e5;

int main(){
	
	vv<ll> a(100002);
    FORN(i, 1, 100000) {
		for(int j=1;j*j<=i;j++){
			if((i%j==0)){
				a[i].push_back(j);
				if(i!=j*j)a[i].push_back(i/j);
			}
		}
		sort(a[i].begin(),a[i].end());
	}
	
	int _t;
	cin>>_t;
	
	REP(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector<int> x(n);
		REP(i,n)cin>>x[i];
		sort(x.begin(),x.end());
		int ans = inf;
		
		vector<int> c(m+1,0);
		int y = 0;
		int l = 0;
		REP(i,n){
			int z = x[i];
			REP(j,a[z].size()){
				if(a[z][j]>m)break;
				c[a[z][j]] ++;
				if(c[a[z][j]]==1)y++;
			}
			
			while(l<=i&&y==m){
				ans = min(ans,x[i] - x[l]);
				z = x[l];
				REP(j,a[z].size()){
					if(a[z][j]>m)break;
					c[a[z][j]] --;
					if(c[a[z][j]]==0)y--;
				}
				l++;
			}
			
			
		}
		if(ans==inf)ans = -1;
		cout<<ans<<endl;
		
	}
	
	return 0;
}
