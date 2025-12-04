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
const int INF = 1e9 + 7;
int query(int x, int n, int y = 1) {
	if (n) {
		cout << "? " << x + 1 << " " << n << " ";
		for (int i = 0; i < n; i++) {
			cout << i + 1 << " ";
		}
		cout << endl;
		int res;
		cin >> res;
		return res;
	} else {
		cout << "? " << x + 1 << " " << 2 << " " << x + 1 << " " << y + 1 << endl;
		int res;
		cin >> res;
		return res;
	}
}
void solve() {
    int n;
    cin >> n;
    vi res(n);
    vvi e(n+1);
    for (int i = 0; i < n; i++) {
    	res[i] = query(i, n);
    	e[res[i]].push_back(i);
    }
    vi ans;
    int prev = -1;
    for (int i = n; i >= 1; i--) {
    	if (e[i].size() && prev == -1) {
    		prev = e[i][0];
    		ans.push_back(e[i][0]);
    	} else if (e[i].size()) {
    		for (int j = 0; j < e[i].size(); j++) {
    			int r = query(prev, 0, e[i][j]);
    			if (r == 2) {
    				prev = e[i][j];
    				ans.push_back(e[i][j]);
    				break;
    			}
    		}
    	} else if (prev != -1) {
    		assert(false);
    	}
    }
    cout << "! " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] + 1 << " ";
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
