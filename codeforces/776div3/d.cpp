#include <bits/stdc++.h>
using namespace std;

int t;
void solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n; i >= 1; i--) {
        int id = 0;
        for (id; id < i; id++) {
            if (arr[id] == i)
                break;
        }
        int mv = (id + 1) % i;
        ans[i - 1] = (id + 1) % i;
        rotate(arr.begin(), arr.begin() + mv, arr.begin() + i);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}