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
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n - 2; i++) {
    	cin >> s[i];
    }
    vector<char> ans;
    ans.push_back(s[0][0]);
    for (int i = 1; i < n - 2; i++) {
    	if (s[i][0] != s[i-1][1]) {
    		ans.push_back(s[i-1][1]);
    		ans.push_back(s[i][0]);
    	} else {
    		ans.push_back(s[i][0]);	
    	}
    }
    ans.push_back(s[n-3][1]);
    if (ans.size() != n) {
    	ans.push_back('a');
    }
    for (int i = 0; i < ans.size(); i++) {
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
