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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> a(m);
    for (int i = 0; i < m; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	a[i] = {x, y, z};
    }
    vi f(n + 2);
    f[1] = 1;
    f[0] = 1;
    for (int i = 2; i <= n + 1; i++) {
    	f[i] = f[i-2] + f[i-1];
    }
    vi ans(m);
    for (int i = 0; i < m; i++) {
    	auto [x, y, z] = a[i];
    	int minn = min(min(x, y), z);
    	int maxx = max(max(x, y), z);
    	if (maxx >= f[n+1] && minn >= f[n]) {
    		ans[i] = 1;
    	}
    }
    for (int i = 0; i < m; i++) {
    	cout << ans[i];
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
