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
    vector<vector<int>> v(4);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if ((x + y) % 2) {
            v[0].push_back(x + y);
            v[1].push_back(x - y);
        } else {
            v[2].push_back(x + y);
            v[3].push_back(x - y);
        }
    }
    for (int i = 0; i < 4; i++) {
        sort(v[i].begin(), v[i].end());
    }
    ll ans = 0;
    for (int x = 0; x < 4; x++) {
        for (int i = 0; i + 1 < v[x].size(); i++) {
            ans += 1ll * (v[x][i+1] - v[x][i]) * (i + 1) * (v[x].size() - i - 1);
        }
    }
    cout << ans / 2 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
