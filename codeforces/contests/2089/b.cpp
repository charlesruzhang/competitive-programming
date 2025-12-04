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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		a[i][j] = s[j] - '0';
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (a[i][j]) {
    			int flag = 1;
    			int cur = i;
    			while (a[cur][j]) {
    				cur--;
    				flag = 0;
    				if (cur < 0) break;
    			}
    			int flag2 = 1;
    			int cur2 = j;
    			while (a[i][cur2]) {
    				cur2--;
    				flag2 = 0;
    				if (cur2 < 0) break;
    			}
    			if (!flag && !flag2) {
    				if (cur >= 0 && cur2 >= 0) {
    					cout << "NO" << endl;
    					return;
    				}
    			}
    		}
    	}
    }
    cout << "YES" << endl;
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
