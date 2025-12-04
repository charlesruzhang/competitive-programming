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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    map<int, int> ma;
    for (int i = 0; i < n; i++) {
    	int x = a[i];
    	for (int j = 2; j * j <= x; j++) {
    		int cnt = 0;
    		while (x % j == 0) {
    			x /= j;
    			cnt++;
    		}
    		if (cnt) {
    			ma[j] += cnt;
    		}
    	}
    	if (x > 1) {
    		ma[x] += 1;
    	}
    }
    ll tot = 0;
    for (auto [x, y] : ma) {
    	tot += y;
    }
    int ans = 0;
    ll tot2 = tot;
    for (auto [x, y]: ma) {
    	int z = y / 2;
    	ans += z;
    	tot2 -= z * 2;
    }

    if (tot2 >= 3) {
    	ans += tot2 / 3;
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
