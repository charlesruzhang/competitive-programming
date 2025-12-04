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
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '0') {
    		x++;
    	} else {
    		y++;
    	}
    }
    if (n % 2 == 1) {
    	if (min(x, y) == 0) {
    		if (k != max(x, y) / 2 + 1) {
    			cout << "No" << endl;
    		} else {
    			cout << "Yes " << endl;
    		}
    		return;
    	}
		if ((x / 2 + y / 2) >= k - 1 && abs(y - x) <= 2 * k - 1 && (2 * k - 1 - abs(y - x)) % 4 == 0) {
			cout << "Yes" << endl;
		} else {
			cout << "no" << endl;
		}
    } else {
    	if ((x / 2 + y / 2) >= k && abs(y - x) <= 2 * k && (2 * k - abs(y - x)) % 4 == 0) {
    		cout << "YEs" << endl;
    	} else {
    		cout << "No" << endl;
    	}
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
