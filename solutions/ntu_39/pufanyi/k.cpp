#include <bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){
    int n; cin >> n;
    unordered_map<string, vector<int>> mp;
    for(int i = 0; i < n; i++){
        string s, ss; int num;
        cin >> s >> ss >> num;
        if(mp[s].size() == 0){
            mp[s] = vector<int>(3, 0);
        }
        if(ss == "left"){
            mp[s][0] += num;
        }
       else if(ss == "right"){
           mp[s][1] += num;
       }
        else{
            mp[s][2] += num;
        }
    }
    bool ok = false;
    int count = 0;
    for(auto &it : mp){
        vector<int> v = it.second;
        if((v[0] && v[1]) || (v[2] && (v[0] || v[1])) || (v[2] > 1)) ok = true;
        int x = v[2] >= 1 ? 1 : 0;
        count += max({v[0], v[1], x});
    }
    if(ok) cout << count + 1 << endl;
    else cout << "impossible" << endl;


    return 0;
}
