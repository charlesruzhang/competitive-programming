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
    string s;
    cin >> s;
    int counter = 0;
    for (char c : s) {
        if (c == '1') {
            counter++;
        }
    }
    cout << counter << endl;
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
