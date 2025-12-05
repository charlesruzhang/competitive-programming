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
void solve() {
    string s;
    vector<string> V;
    while (1) {
    	cin >> s;
    	if (s == "!") break;
    	V.push_back(s);
    }
    int n = V.size();
    int m = V[0].size();
    int ans = 0;
    while (1) {
    	vector<string> W = V;
	    for (int i = 0; i < n; i++) {
	    	for (int j = 0; j < m; j++) {
	    		if (V[i][j] == '@') {
	    			int cnt = 0;
	    			for (int k = -1; k <= 1; k++) {
	    				for (int l = -1; l <= 1; l++) {
		    				int x = i + k;
		    				int y = j + l;
		    				if (x < n && x >= 0 && y < m && y >= 0) {
		    					if (V[x][y] == '@') {
		    						cnt++;
		    					}
		    				}
	    				}
	    			}
	    			if (cnt <= 4) {
	    				W[i][j] = '.';
	    				ans++;
	    			}
	    		}
	    	}
	    } 
	    if (V == W) break;
	    swap(W, V);
	}
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
