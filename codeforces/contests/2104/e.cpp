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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<set<int>> vs(k);
    for (int i = 0; i < n; i++) {
    	int c = s[i] - 'a';
    	vs[c].insert(i);
    }		
    vi dp(n+1);
    dp[n] = 1;
    for (int i = n-1; i>=0; i--) {
    	int maxx = i;
    	int flag1 = 1;
    	for (int j = 0; j < k; j++) {
			auto it = vs[j].lower_bound(i);
			if (it == vs[j].end()) {
				flag1 = 0;
				break;
			}
			maxx = max(maxx, *it);
		}
		if (!flag1) {
			dp[i] = 1;
		} else {
			dp[i] = dp[maxx+1] + 1;
		}
    }
    int q;
    cin >> q;
    while (q--) {
    	string t;
    	cin >> t;
    	int l = 0;
    	int flag = 1;
    	for (int i = 0; i < t.size(); i++) {
    		int c = t[i] - 'a';
    		auto it = vs[c].lower_bound(l);
    		if (it == vs[c].end()) {
    			flag = 0;
    			break;
    		}
    		l = *it + 1;
    	}
    	if (!flag) {
    		cout << 0 << endl;
    		continue;
    	}
    	cout << dp[l] << endl;
    }
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
