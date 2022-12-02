#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {

    ll n;
    cin >> n;
    vector<int> nums(n);

    for (int i=0;i<n;i++) cin>>nums[i];
    sort(nums.begin(), nums.end());
    if (nums.front() == nums.back()) {
        cout<<n/2<<endl;
        return;
    }

    auto middle = n/2-1;
    if (nums[middle] != nums[middle+1]) {
        cout<< (n/2)*((n+1)/2) <<endl;
        return;
    }
    ll start = middle, end = middle;
    for (;start&&nums[start]==nums[start-1];start--);
    for (;end<n-1&&nums[end]==nums[end+1];end++);
    end++;

    cout << max(start*(n-start), end*(n-end)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
