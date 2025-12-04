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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	a[i] = s[i] - '0';
    }
    int q;
    cin >> q;
    int tot = 0;
    for (int i = 3; i < n; i++) {
    	if (a[i] == 0 && a[i-1] == 0 && a[i-2] == 1 && a[i-3] == 1) {
    		tot++;
    	}
    }
    for (int i = 0; i < q; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--;
    	if (a[x] == y) {
    		if (tot) cout << "YES" << endl;
    		else cout << "NO" << endl;
    		continue;
    	}
    	for (int j = x; j <= min(x + 3, n - 1); j++) {
    		if (j >= 3 && a[j] == 0 && a[j-1] == 0 && a[j-2] == 1 && a[j-3] == 1) {
    			tot--;
    		}  
    	}
    	a[x] = y;
    	for (int j = x; j <= min(x + 3, n - 1); j++) {
    		if (j >= 3 && a[j] == 0 && a[j-1] == 0 && a[j-2] == 1 && a[j-3] == 1) {
    			tot++;
    		}  
    	}
    	if (tot) cout << "YES" << endl;
    		else cout << "NO" << endl;
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
