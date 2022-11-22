#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main(){
    long long r,c,h,q,n;
    cin >> r >> c >> h >> q;
    long long t = r*c, v=0;
    
    vector<long long> num(h), ans(h), sum(h);
    for (int i=0;i<t;i++) {
        cin >> n;
        num[n]++;
    }
//    for(int j = 0; j < 10; j++){
//        cout << num[j] << endl;
//    }
    
    ans[0] = 0;
    for (int i=1;i<h;i++) {
        v += num[i-1];
        ans[i] = ans[i-1]+v;
    }
    for (int i=1;i<h;i++) {
        sum[i] = sum[i-1] + num[i-1];
    }

    while (q--) {
        cin >> v;
        if (v == 0) {
            cout << t << endl;
            continue;
        }
        if (v>=sum[h-1]) {
            cout << 0 << endl;
            continue;
        }
        long long start=1,end=h-1,cur;
        while (start<end) {
            cur = (end-start)/2+start;
            if (ans[cur] == v) {
                cout << t-sum[cur] << endl;
                break;
            }
            if (ans[cur]>v) {
                if (ans[cur-1]<v) {
                    cout << t-sum[cur] << endl;
                    break;
                }
                end = cur;
                continue;
            }
            if (ans[cur+1]>=v) {
                cout << t-sum[cur+1] << endl;
                break;
            }
            start = cur;
            continue;
        }
    }
    
    return 0;
}
