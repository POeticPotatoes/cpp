#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int n;
set<int> a, b;

int bob();

int alice() {
    if (a.size() == 1)
        return abs(*(a.begin()) - *(b.begin()));
    int m;

    for (auto t: a) {
        a.erase(t);
        m = max(m, bob());
        a.insert(t);
    }
    return m;
}

int bob() {
    int m=0;

    for (auto t: b) {
        b.erase(t);
        m = min(m, alice());
        b.insert(t);
    }
    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    return alice();
}
