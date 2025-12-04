#include <bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int solve() {
    int n, m, q, a, ans;
    int b[10];
    cin >> n >> m >> q;
    for (int i =0; i<m; ++i) {
        cin >> b[i];
    }
    sort(b, b + m);
    int cq = q;

    while (cq --) {
        cin >> a;
        int left = 0;
        int right = m-1;
        if (a < b[left]) ans = b[0] -1;
        else if (a > b[right]) ans = n - b[right];
        else {
            while (left < right - 1) {
                int m = (left + right) / 2;
                if (m < a) {left = m;}
                else {right = m;}
            }
            ans = (b[left] + b[right]) / 2;
        }
        cout << ans << "\n"; 
    }
    return 0;
}


signed main() {
    IOS
    int t;
    cin >> t;
    cout << "ello";
    while (t--) {
        solve();
    }
    return 0;
}