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
const ll MAXX = 1e18;
const int INF = 1e9 + 7;
void solve() {
    int n, k;
    cin >> n >> k;
    k++;
    int x = k * (k - 1) / 2 + n;
    ll res = 2 * MAXX;
    for (int i = 0; x - i * 9 >= 0; i++) {
    	if ((x - 9 * i) % k == 0) {
    		int m = (x - 9 * i) / k;
    		if (i == 0) {
    			vi ans;
    			while (m > 0) {
    				int z = min(9, m);
    				ans.push_back(z);
    				m -= z;
    			}
    			reverse(ans.begin(), ans.end());
    			ll ret = 0;
    			for (int v : ans) {
    				ret *= 10;
    				ret += v;
    			}
    			ret -= k - 1;
    			if (ret < 0) continue;
    			res = min(res, ret);
    			continue;
    		}
    		vi summ(k);
    		summ[k-1] = m;
    		for (int j = k - 2; j >= 0; j--) {
    			summ[j] = summ[j+1] - 1;
    		}
    		for (int j = 1; j < k; j++) {
    			if (i % j) continue;
    			if (summ[j] <= 0) continue;
    			int times = i / j;
    			//cout << "??" << times << " " << m << " " << i << " " << j << " " << summ[j] << endl;
    			int y = summ[j];
    			vi ans;
    			for (int t = 0; t < times; t++) {
    				ans.push_back(0);
    			}
    			while (y > 0) {
    				int z = min(9, y);
    				ans.push_back(z);
    				y -= z;
    			}
    			reverse(ans.begin(), ans.end());
    			ll ret = 0;
    			for (int v : ans) {
    				ret *= 10;
    				ret += v;
    			}
    			ret -= j;
    			res = min(res, ret);
    		}
    	}
    }
	if (res != 2 * MAXX) {
		cout << res << endl;
	} else {
		cout << -1 << endl;
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
