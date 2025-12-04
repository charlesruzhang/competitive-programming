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
    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
    	cin >> vs[i];
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (vs[i][j] != '#') continue;
    		int cnt = 0;
    		if (i && vs[i-1][j] == '#') cnt++;
    		if (i != n - 1 && vs[i+1][j] == '#') cnt++;
    		if (j && vs[i][j-1] == '#') cnt++;
    		if (j != m - 1 && vs[i][j+1] == '#') cnt++;
    		if (cnt != 2 && cnt != 4) {
    			flag = 0;
    			break;
    		} 
    	}
    	if (!flag) break;
    }
    cout << ((flag) ? "Yes" : "No") << endl;
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
