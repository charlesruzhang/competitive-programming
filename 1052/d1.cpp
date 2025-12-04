// By Auchenai01
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
const int INF = 1e9 + 7;
void solve() {
    int l, r;
    cin >> l >> r;
    if (r == 0) {
    	cout << 0 << endl;
    	cout << 0 << endl;
    	return;
    }
    int z = 32 - __builtin_clz(r);
    int summ = (1 << z) - 1;
    int n = r - l + 1;
    vi ans(n, -1);
    ll tot = 0;
    for (int i = n - 1; i >= 0; i--) {
    	if (ans[i] != -1) continue;
    	while (summ - i >= n || ans[summ - i] != -1) {
    		summ >>= 1;
    	}
    	ans[i] = summ - i;
    	ans[summ - i] = i; 
    	tot += 2 * ((summ - i) | i);
    }
    cout << tot << endl;
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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
