#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

void solve() {
    priority_queue<ll> top, bottom;
    bool flag=false;
    ll n,p, lowest, chain, tens=0, last, cur;
    cin >> n >> p;
    vector<ll> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
        top.push(nums[i]);
    }
    last = nums[n-1];
    for (int i=n-2;i>=0;i--)
        if (nums[i]!=p-1) {
            tens = nums[i];
            break;
        }

    for (auto i:nums) if (i<last) bottom.push(i);

    for (lowest=p;lowest;lowest--){
        while (top.size()&&top.top()>=lowest) top.pop();
        if (top.empty() || lowest-top.top()>1)
            break;
    }
    flag = last-tens== 2 && (bottom.empty() || bottom.top()!=last-1);
    for (chain=flag?tens:last;chain;chain--){
        while (bottom.size()&&bottom.top()>=chain) bottom.pop();
        if (bottom.empty() || chain-bottom.top()>1)
            break;
    }

    // cout << "Flag: "<<flag<<" lowest: "<<lowest<<" chain: "<<chain<<" tens: "<<tens<<" last: "<<last<<endl;

    if (lowest == 0) {
        cout << 0<<endl;
        return;
    }
    
    if (chain == 0) {
        cout<<(flag?p-last:lowest-last-1)<<endl;
        return;
    }
    
    cout<<p+chain-last-1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
