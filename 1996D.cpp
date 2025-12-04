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
    int n, x;
    cin >> n >> x;
    ll cnt = 0;
    for (int i = 1; i <= x - 2; i++) {
    	int z = n / i;
    	for (int j = 2; j <= min(x - i, z); j++) {
    		int maxx = n - j * i;
    		int l = 1;
    		int r = j / 2;
    		if (1ll * r * (j - r) <= maxx) {
    			cnt += j - 1;
    			continue;
    		}
    		if (1ll * l * (j - l) > maxx) {
    			//continue;
    		}  
    		while (l < r) {
    			int mid = (l + r + 1) / 2;
    			if (1ll * mid * (j - mid) <= maxx) {
    				l = mid;
    			} else {
    				r = mid - 1;
    			}
    		}
    		cnt += l * 2;
    	}
    	//cout << i << " " << cnt << endl;
    }
    cout << cnt << endl;
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
