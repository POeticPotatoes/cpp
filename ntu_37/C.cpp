#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
#define ll long long
using namespace std;

double distribute(vector<ll> *orig, bool o) {

    deque<ll> order;
    auto s = orig->begin(), b = orig->end();

    for (b--;b>=s;o=!o) {

        int a = o?*b--:*s++;
        int f=0,e=0;

        if (order.size()) f=abs(a-order.back()), e=abs(a-order.front());

        if (f<e) order.emplace_front(a);
        else order.emplace_back(a);
    }

    double ans = order.front() + order.back();
    int n = order.size()-1;

    for (int i=0;i<n;i++) ans += 2* sqrt(order[i] * order[i+1]);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<ll> orig(n);
    for (int i=0;i<n;i++) cin >> orig[i];

    sort(orig.begin(), orig.end());
    double ans = min(distribute(&orig, true), distribute(&orig, false));

    printf("%.5f\n", ans);
}
