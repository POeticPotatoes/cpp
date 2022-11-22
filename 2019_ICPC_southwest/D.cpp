#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<char, int> chars;
    string s, ans;
    int m=0, l=0, h;
    cin >> s;
    h = s.size()/2;

    for (auto c: s) {
        if (chars.find(c) == chars.end())
            chars[c] = 0;
        chars[c]++;
        if (chars[c] > m) {
            m = chars[c];
            l = c;
        }
    }

    if (chars.size() == 1) {
        cout << "NO" << endl;
        return 0;
    }

    if (m <= h) {
        for (auto c: chars) while (c.second--) ans+= c.first;
        cout << "YES" << endl;
        cout << ans << endl;
        return 0;
    }

    auto p = chars.begin();
    if (p->first == l) p++;
    if (chars.size() == 2) {
        if (p->second < 3) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    while (h--) {
        ans += l;
        chars[l]--;
    }
    ans += p->first;
    chars[p->first]--;
    while (chars[l]--) ans += l;
    for (auto c: chars) while (c.second-- > 0) ans+= c.first;
    cout << ans << endl;
}
