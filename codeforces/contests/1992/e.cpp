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
    vi vec;
    int z = n;
    while (z > 0) {
    	vec.push_back(z % 10);
    	z /= 10;
    }
    reverse(vec.begin(), vec.end());
    int m = vec.size();
    int idx = 0;
    int cur = 0;
    vector<pii> ans;
    while (cur <= n * 10000) {
    	cur = cur * 10 + vec[idx % m];
    	idx++;
    	for (int i = 1; i <= 10000; i++) {
    		int b1 = n * i - cur;
    		int b2 = vec.size() * i - idx;
    		if (b1 > 0 && b1 == b2) {
    			ans.push_back({i, b1});
    		}
    	}
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i].first << " " << ans[i].second << endl;
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
