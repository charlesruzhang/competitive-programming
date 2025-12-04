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
    ll k;
    cin >> n >> k;
    vector<ll> tri;
    for (int i = 1; i < n; i++) {
    	tri.push_back(1ll * i * (i + 1) / 2);
    }
    ll tot = 1ll * n * (n - 1) * (n - 2) / 6;
    if (k - 1 > tot) {
    	cout << "NO" << endl;
    	return;
    }
    vl ans;
    ll x = tot - k;
    for (int i = n - 3; i >= 0; i--) {
    	if (tri[i] <= x) {
    		x -= tri[i];
    		ans.push_back(i+1);
    	}
    }
    //cout << x << " ?? " << endl;
    cout << "YES" << endl;
    for (int i = 1; i < n - ans.size(); i++) {
    	cout << i << " " << i + 1 << endl;
    }
    for (int i = 0; i < ans.size(); i++) {
    	cout << n - i << " " << n - i - 1 - ans[i] << endl;
    }
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
