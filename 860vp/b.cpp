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
    int m;
    cin >> m;
    vvi a(m);
    for (int i = 0; i < m; i++) {
    	int n;
    	cin >> n;
    	a[i].resize(n);
    	for (int j = 0; j < n; j++) {
    		cin >> a[i][j];
    	}
    }
    vi ans;
    set<int> S;
    for (int i = m - 1; i >= 0; i--) {
    	int flag = 0;
    	for (int j = 0; j < a[i].size(); j++) {
    		if (S.find(a[i][j]) != S.end()) {
    			continue;
    		} else {
    			S.insert(a[i][j]);
    			flag = a[i][j];
    		}
    	}
    	if (flag) {
    		ans.push_back(flag);
    	} else {
    		cout << -1 << endl;
    		return;
    	}
    }
    reverse(ans.begin(), ans.end());
    for (int x: ans) {
    	cout << x << " ";
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
