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
    string s;
    cin >> s;
    vi pref(n);
    vi ans(n);
    ans[0] = 1;
    vi ans2(n);
    vvi valid(n, vi(2));
    int prev = 0;
    for (int i = 1; i < n; i++) {
    	pref[i] = pref[i-1] + ((s[i] == s[i-1]) ? 0 : 1);
    	ans[i] = i - pref[i] + 2 ;
    	if (pref[i] == 0) {
    		ans[i]--;
    	}
    	int x = 0;
    	if (i != n-1 && s[i+1] != s[i]) {
    		x = 1;
    	}
    	valid[pref[i]][x] = 1;
    	ans2[i] = ans2[i-1];
    	if (s[i] == s[i-1]) {
    		continue;
    	}
    	vi vec;
    	for (int j = 2; j * j <= (pref[i] + 1) ; j++) {
    		if ((pref[i] + 1) % j == 0) {
    			vec.push_back(j);
    			if (j * j != (pref[i] + 1)) vec.push_back((pref[i] + 1) / j);
    		}
    	}
    	ans2[i] -= prev;
    	prev = 0;    	
    	for (int y : vec) {
    		int flag = 1;
    		int flag2 = 1;
    		int flag3 = 0;
    		for (int j = y; j <= (pref[i] + 1); j+=y) {
    			if (!valid[j][0]) {
    				flag = 0;
    			}
    			if (!valid[j - 1][1]) {
    				flag2 = 0;
    			}
    			if (flag && (j == pref[i] + 1 - y)) {
    				flag3 = 1;
    			}
    		}
    		if (!flag && flag2) {
    			prev++;
    			ans2[i]++;
    		}
    		if (flag3 && !flag) {
    			ans2[i]--;
    		}
    	}
    }
    // for (int i = 0; i < n; i++) {
    // 	cout << ans[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
    	cout << ans[i] + ans2[i] << " ";
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
