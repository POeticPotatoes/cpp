#include "/Users/poeticpotato/Desktop/Work/cpp/bits.h"
using namespace std;

vector<bool> bdays(100000);
int start=100000;
int e= 0;

void read() {
    string s;
    cin >> s;
    int i = 0;
    string year, month;
    while(s[i] != '-') {
        year += s[i];
        i++;
    }
    i++;
    while(s[i] != '-') {
        month += s[i];
        i++;
    }

    int y = stoi(year), m = stoi(month);
    start = min(y, start);
    e = max(y, e);
    if (m < 3)
        bdays[y] = true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pair<int,int>> buf(n+1);

    for (int i = 0; i < n + 1; ++i) {
        read();
    }

    int count = 0;
    for (int i=start+1; i<=e; i++) {
        count += !bdays[i];
    }
    cout << count << endl;
    for (int i=start+1; i<=e; i++) {
        if (!bdays[i])
            cout << i << "-02-02" << endl;
    }
}
/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    for (int i=start; i<end; i++) {
        if (!bdays[i]) {
            // Output the date here
        }
    }
}
*/
