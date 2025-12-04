#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
int solve() {
    int n;
    cin >> n;
    vvi a(n, vi(n, 0));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vi x(n+1, 0);
    for (int i = 0; i < n; i ++) {
        int summ = 0;
        for (int j = n-1; j >= 0; j--) {
            if (a[i][j] == 1) {
                summ += 1;
            } else {
                break;
            }
        }
        x[summ]++;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (x[i] != 0) {
            ans=min(x[i]+ans,i);
        }
    }
    ans = min(ans, n-1);
    cout << ans +1 <<endl;
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
