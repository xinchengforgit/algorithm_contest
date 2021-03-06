#include <bits/stdc++.h>

using namespace std;
const int maxn = 600000 + 50;
int tr[maxn][3];

inline int lowbit(int x) {
    return x & (-x);
}

int n;

int query(int x, int op) {
    int ans = 0;
    while (x) {
        ans += tr[x][op];
        x -= lowbit(x);
    }
    return ans;
}

void update(int x, int op) {
    while (x <= 2 * n) {
        tr[x][op]++;
        x += lowbit(x);
    }
}

void solve() {
    cin >> n;
    int x = 0;
    string str;
    cin >> str;
    long long ans = 0;
    //
    for (int i = 1; i <= 3 * n; i++) {
        tr[i][0] = tr[i][1] = tr[i][2] = 0;
    }
    update(n + 1, 0);
    for (int i = 0; i < str.size(); i++) {
        x += (str[i] == '-') ? 1 : -1;
        ans += query(x + n + 1, (x % 3 + 3) % 3);
        update(x + n + 1, (x % 3 + 3) % 3);
    }
    cout << ans << endl;
}

int t;

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}