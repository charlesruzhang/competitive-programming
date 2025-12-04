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
	vvi d(3, vi(6));
    for (int i = 0; i < 3; i++){
    	for (int j = 0; j < 6; j++) {
    		cin >> d[i][j];
    	}
    }
    auto check = [&](int i, int j) {
    	int p = 0;
    	int q = 0;
    	for (int x = 0; x < 6; x++) {
    		for (int y = 0; y < 6; y++) {
    			if (d[i][x] < d[j][y]) {
    				q++;
    			} else if (d[i][x] > d[j][y]) {
    				p++;
    			}
    		}
    	}
    	if ((p + q) == 0) return 0.0; 
    	return ((double) p) / ((double) (p + q));
    };
    for (int i = 0; i < 3; i++) {
    	int flag = 1;
    	for (int j = 0; j < 3; j++) {
    		if (i == j) {
    			continue;
    		}
    		double p = check(i,j);
    		if (p < 0.5) {
    			flag = 0;
    			break;
    		}
    	}
    	if (flag) {
    		cout << i + 1 << endl;
    		return;
    	}
    }
    cout << "No dice" << endl;

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
