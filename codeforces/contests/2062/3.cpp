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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    int maxx = -500000;
    for (int i = n; i >= 1; i--) {
        int summ = 0;
        for (int j =0; j < i; j++) {
            summ += a[j];
        }
        maxx = max(maxx, summ);
        if (i != n) {
            maxx = max(maxx, -summ);
        }
        for (int j = 0; j < i-1; j++) {
            a[j] = a[j+1] - a[j];
        }
    }
    cout << maxx << endl;
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
