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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int x = -1;
    int tot = 0;
    while (x < n) {
    	if (x + m >= n) {
    		cout << "YES" << endl;
    		return;
    	}
    	int flag = 0;
    	for (int i = m; i >= 1; i--) {
    		if (s[x + i] == 'L') {
    			x = x + i;
    			flag = 1;
    			break;
    		}
    	}
    	if (flag) continue;
    	x += m;
    	while (x < n) {
    		if (s[x] == 'C') {
    			cout << "No" << endl;
    			return;
    		} else if (s[x] == 'W') {
    			tot++;
    			if (tot > k) {
    				cout << "NO" << endl;
    				return;
    			}
    		} else {
    			break;
    		}
    		x++;
    	}
    }
    cout << "Yes" << endl;
    return;
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
