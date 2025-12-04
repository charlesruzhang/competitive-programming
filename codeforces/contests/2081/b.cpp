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
    vector<pii> v;
    int cur = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (i) {
    		if (a[i-1] > a[i]) {
    			cur++;
    		} else {
    			if (cur) v.push_back({cur, i - 1});
    			cur = 0;
    		}
    	} 
    }
    if (cur) v.push_back({cur, n-1});
    int ans = 1e9+7;
    //case 1:
    vector<pii> w = v;
    if (!v.size()) {
    	cout << 0 << endl;
    	return;
    }
    if (w[0] >= w.back()) {
    	w[0].first--;
    } else {
    	w[w.size()-1].first--;
    }
    int summ = 0;
    int maxx = 0;
    for (int i = 0; i < w.size(); i++) {
    	summ += w[i].first;
    	maxx = max(maxx, w[i].first);
    }
    if (2 * maxx > summ) {
    	ans = min(ans, maxx + 1);
    } else {
    	ans = min(ans, (summ + 1) / 2 + 1);
    }
    //case 2:
    int l = 0;
    int r = n - 1;
    while (l < r && a[r] - a[l] >= n - 1) {
    	l++;
    	r--;
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
