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
    cin  >> n;
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'a' || s[i] == 'e') {
    		ans.push_back(s[i]);
    	} else {
    		if (i != n-1 && (s[i+1] == 'c' || s[i+1] == 'd' || s[i+1] == 'b')) {
    			
    		ans.push_back(s[i]);
    		ans.push_back(".");
    		} else {
    		ans.push_back(".");
    		ans.push_back(s[i]);
    		}
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
