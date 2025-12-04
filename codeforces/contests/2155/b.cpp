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
    int n, k;
    cin >> n >> k;
    if (k == n * n) {
    	cout << "YES" << endl;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			cout << "U";
    		}
    		cout << endl;
    	}
    	return;
    }
    if (k > n * n - 2) {
    	cout << "NO" << endl;
    	return;
    }
    cout << "YEs" << endl;
    int req = n * n - k;
    vector<vector<char>> ans(n, vector<char>(n, 'D'));
    ans[0][0] = 'R';
    ans[0][1] = 'L';
    int tot = 2;
    if (tot == req) {
		for (int z = 0; z < n; z++) {
			for (int x = 0; x < n; x++) {
				cout << ans[z][x];
			} 
			cout << endl;
		}
		return;
	}
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (i >= 1 || j >= 2) {
    			if (i < 1) {
    				ans[i][j] = 'L';
    			} else {
    				ans[i][j] = 'U';
    			}
    			tot++;
    			if (tot == req) {
					for (int z = 0; z < n; z++) {
						for (int x = 0; x < n; x++) {
							cout << ans[z][x];
						} 
						cout << endl;
					}
					return;
				}
    		}
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
