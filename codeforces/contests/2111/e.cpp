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
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cum = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int w = 0;
    int cum2 = 0;
    for (int i = 0; i < q; i++) {
    	string t, u;
    	cin >> t >> u;
    	if (t == "b" && u == "c") {
    		cum++;
    	}
    	if (t == "c" && u == "a") {
    		if (cum > 0) {
    			cum--;
    			x++;
    		}
    		y++;
    	}
    	if (t == "c" && u == "b") {
    		cum2++;
    	}
    	if (t == "b" && u == "a") {
    		w++;
    		if (cum2 > 0) {
    			z++;
    			cum2--;
    		}
    	}
    }

    vector<char> ans(n);
    for (int i = 0; i < n; i++) {
    	ans[i] = s[i];
    }
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'a') {
    		continue;
    	}
    	if (s[i] == 'b') {
    		if (w > 0) {
    			w--;
    			ans[i] = 'a';
    		} else {
    			if (x > 0 && y > 0) {
    				x--;
    				ans[i] = 'a';
    				y--;
    			}
    		}
    	}
    	if (s[i] == 'c') {
    		if (y > 0) {
    			y--;
    			ans[i] = 'a';
    		} else if (z > 0 && w > 0) {
    			z--;
    			w--;
    			ans[i] = 'a';
    		} else if (z > 0) {
    			z--;
    			ans[i] = 'b';
    		} else if (cum2 > 0) {
    			cum2--;
    			ans[i] = 'b';
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i];
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
