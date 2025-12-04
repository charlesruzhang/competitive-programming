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
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi ma(2 * n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	ma[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= k / 2; i++) {
    	if (2 * i != k) ans += min(ma[i], ma[k-i]);
    	else ans += ma[i] / 2;
    }
    cout << ans << endl;
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
