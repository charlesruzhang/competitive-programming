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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi ans;
    for (int x = 29; x >= 0; x--) {
    	int maxx = 0;
    	ll summ = 0;
    	for (int i = 0; i < n; i++) {
    		if (a[i] >= (1 << x) && a[i] < (1 << (x+1))) {
    			maxx = max(maxx, a[i]);
    		}
    		if (a[i] < (1 << (x+1))) {
    			summ += a[i];
    		}
    	}
    	if (!maxx || maxx * 2 >= summ) {
    		continue;
    	}
    	vi v;
    	int flag = 0;
    	for (int i = 0; i < n; i++) {
    		if (a[i] > maxx) continue;
			while (!v.empty() && a[i] > v.back() && summ - v.back() > 2 * maxx) {
				summ -= v.back();
				v.pop_back();
			}
    		v.push_back(a[i]);
    	}
    	if (v.size() > 2 && ans < v) {
    		swap(ans, v);
    	}
    }
    if (!ans.size()) {
    	cout << -1 << endl;
    	return;
    }
    cout << ans.size() << endl;
    for (int i= 0; i < ans.size(); i++) {
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
