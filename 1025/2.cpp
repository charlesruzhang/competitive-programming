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
int LIS (vi & vec) {
	int m = vec.size();
	vi best(m+1, 1e9);
	best[0] = 0;
	for (int i = 0; i < m; i++) {
		int l = 0;
		int r = m;
		while (l < r) {
			int mid = (l + r) / 2;
			if (best[mid] >= vec[i]) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		best[l] = vec[i];
	}
	for (int i = 1; i <= m; i++) {
		if (best[i] == 1e9) {
			return i - 1; 
		}
	}
	return m;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int best = 1e9;
    for (int i = n-1; i >= 0; i--) {
    	if (a[i] < k) continue;
    	vi vec;
    	for (int j = 0; j < i; j++) {
    		if (j + 1 - a[j] >= 0 && a[j] < a[i] && a[i] - a[j] <= i - j) {
    			vec.push_back(a[j]);
    		}
    	}
    	int res = LIS(vec);
    	if (res >= k - 1) {
    		best = min(best, i + 1 - a[i]);
    	}
    	//cout << i << " , " << res << endl;
    }
    if (best == 1e9) {
    	cout << -1 << endl;
    } else {
    	cout << best << endl;
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
