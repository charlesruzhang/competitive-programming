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
    string s;
    string t;
    cin >> s >> t;
    int ans = 0;
    int tight = 0;
    for (int i = 0; i < s.size(); i++) {
    	int x = s[i] - '0';
    	int y = t[i] - '0';
    	if (tight) {
    		if (x != 9 || y != 0) {
    			break;
    		}
    		ans++;
    		continue;
    	}
    	if (s[i] == t[i]) {
    		ans += 2;
    	} else if (x + 1 == y) {
    		ans += 1;
    		tight = 1;
    	} else {
    		break;
    	}
    }
    cout << ans << endl;
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
