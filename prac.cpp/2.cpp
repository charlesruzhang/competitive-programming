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
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    int tot = 0;
    for (int i = 0; i < (1 << n); i++) {
    	vi ans;
    	for (int j = 0; j < n; j++) {
    		if ((1 << j) & i) {
    			ans.push_back(a[j]);
    		}
    	}
    	int flag = 1;
    	if (ans.size() == 0 || ans.back() - ans[0] < x) {
    		flag &= 0;
    	}
    	ll summ = accumulate(ans.begin(), ans.end(), 0ll);
    	if (summ < l || summ > r) {
    		flag &= 0;
    	}
    	tot += flag;
    }
    cout << tot << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
