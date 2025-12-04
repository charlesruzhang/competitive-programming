#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
int solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int r = n - k;
    if (r == 0) {
        int count = 1;
        for (int j = 1; j < n; j+=2) {
            if (a[j]!=count) {
                cout << count << endl;
                return 0;
            }
            count++;
        }
        cout << count << endl;
        return 0;
    }
    for (int i = 1; i <= r+1; i++) {
        if (a[i] != 1) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
