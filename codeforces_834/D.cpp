#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

void solve() {
    ll n,m,a,p,i,end=0,start;
    cin>>n>>m;
    if (m==1) {
        cout <<n<<endl;
        return;
    }
    string times = to_string(m),
           val = to_string(n);

    a = times.size();
    p = pow(10,a-1);
    for (i=a-1;i&&val[i]=='0';i--);
    for (start=0;start<a&&times[start]=='1';start++)
        end=(end*10+times[start]-48),p/=10;
    if (val[i] == '5') {
        if (start == a) {
            cout << n*pow(10,a-1)<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)solve();
}
