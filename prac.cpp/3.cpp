#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 998244353;
const ll MAXX = 1e16;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi t(n);
    for (int i = 0; i < n; i++) {
    	t[i] = s[i] - '0';
    }
    ll minn = 1e18;
    for (int i = 0; i < n - 1; i++) {
        vi u;
        for (int j = 0; j < n; j++) {
            if (j == i+1) continue;
            if (j == i) u.push_back(10 * t[j] + t[j+1]);
            else u.push_back(t[j]);
        }
        ll tot = 0;
        for (int j = 0; j < n - 1; j++) {
            if (u[j] == 0) {
                cout << 0 << endl;
                return;
            }
            if (u[j] != 1) {
                tot += u[j];
            }
        }
        tot = max(1ll, tot);
        minn = min(minn, tot);
        //cout << tot << " " << i << endl;
    }
    cout << minn << endl;
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
