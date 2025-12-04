#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
const ll MOD = 998244353;
const ld EPS = 1e-9;

ll solve() {
    ll n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b = 2 * n -1;
    for (int i = 0; 2 * i < n; i++) {
        if (a[i] < b || a[n-i-1] < b) {
            cout << "No" << endl;
            return 0;
        }
        b -= 2;
    }
    cout << "Yes" << endl;
    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
