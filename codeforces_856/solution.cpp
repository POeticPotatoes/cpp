#include <bits/stdc++.h>
#ifdef DEBUG
    #include </home/poeticpotato/work/cpp/debug.h>
#else
  #define deb(x...)
#endif
using namespace std;
typedef long long ll;
 
const int MAXN = 200005;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
 
//Hashing stuff
const ll MOD[3] = {999727999, 1070777777, 1000000007};
vector<long long> B(3);
 
vector<ll> shift(vector<ll> h, ll val = 0){
	for(int k = 0; k < 3; k++){
		h[k] = (h[k] * B[k] + val) % MOD[k];
	}
	return h;
}
 
vector<ll> add(vector<ll> a, vector<ll> b){
	vector<ll> res(3);
	for(int k = 0; k < 3; k++){
		res[k] = (a[k] + b[k]) % MOD[k];
	}
	return res;
}
 
vector<ll> sub(vector<ll> a, vector<ll> b){
	vector<ll> res(3);
	for(int k = 0; k < 3; k++){
		res[k] = (a[k] - b[k] + MOD[k]) % MOD[k];
	}
	return res;
}
 
//Tree stuff
vector<int> g[MAXN];
 
bool vis[MAXN];
int parent[MAXN];
vector<ll> dp[MAXN], dp2[MAXN];
 
void dfs(int x){
	vis[x] = true;
	for(auto i : g[x]){
		if(!vis[i]){
			parent[i] = x;
			dfs(i);
			dp[x] = add(dp[x], shift(dp[i]));
		}
	}
	dp[x] = add(dp[x], {1, 1, 1});
    deb(x+1, dp[x]);
}
 
void dfs2(int x){
	if(x != 0){
		dp2[x] = sub(dp[parent[x]], shift(dp[x]));
		dp2[x] = add(dp2[x], shift(dp2[parent[x]]));
	}
    deb(x+1, dp2[x]);
	for(auto i : g[x]){
		if(i != parent[x]){
			dfs2(i);
		}
	}
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// for(int k = 0; k < 3; k++){
	// 	B[k] = rng() % MOD[k];
	// }
    B = {3,3,3};
	//reading the input
	int n; cin >> n;
	vector<int> occurrences(n);
	for(int i = 0; i < n - 1; i++){
		int a; cin >> a;
		occurrences[a]++;
	}
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//calculating possible list hashes
	vector<vector<ll>> list_hashes;
	vector<ll> h = {0, 0, 0};
	for(int i = n - 1; i >= 0; i--){
		h = shift(h, occurrences[i]);
        deb(h);
	}
    deb("Initial:", h);
	vector<ll> extra = {1, 1, 1};
	for(int i = 0; i < n; i++){
		list_hashes.push_back(add(h, extra));
		extra = shift(extra);
	}
    deb(list_hashes);
	//calculating possible tree hashes
	for(int i = 0; i < n; i++){
		dp[i] = {0, 0, 0};
		dp2[i] = {0, 0, 0};
	}
	parent[0] = -1;
	dfs(0);
	dfs2(0);
	vector<pair<vector<ll>, int>> tree_hashes;
	for(int i = 0; i < n; i++){
		if(i == 0){
			tree_hashes.push_back({dp[i], i});
		}else{
			tree_hashes.push_back({add(dp[i], shift(dp2[i])), i});
		}
        deb(i+1, tree_hashes.back().first);
	}
	//calculting the answer
	sort(list_hashes.begin(), list_hashes.end());
	sort(tree_hashes.begin(), tree_hashes.end());
	vector<int> res;
	int pos = 0;
	for(auto lh : list_hashes){
		while(pos < n && tree_hashes[pos].first < lh){
			pos++;
		}
		while(pos < n && tree_hashes[pos].first == lh){
			res.push_back(tree_hashes[pos].second);
			pos++;
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for(auto i : res){
		cout << i + 1 << " ";
	}
	cout << "\n";
	return 0;
}
