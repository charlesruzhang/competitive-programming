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
    vi L(n), R(n);
    int x = -1, y = n;
    for (int i = 0; i < m; i++) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	L[l] = 1;
    	R[r] = 1;
    	x = max(x, l);
    	y = min(y, r);
    }
    auto print = [&] (vi ans) {
    	for (int x : ans) {
    		cout << x << " ";
    	}
    	cout << endl;
    };
    if (x <= y) {
    	vi ans(n, -1);
    	ans[x] = 0;
    	int cur = 1;
    	for (int i = 0; i < n; i++) {
    		if (ans[i] == -1) {
    			ans[i] = cur++;
    		}
    	}
    //cout << "!0" << endl;
    	print(ans);
    	return;
    }
    
    for (int i = 0; i < n; i++) {
    	if (i && !L[i]) {
    		vi ans(n, -1);
    		ans[i - 1] = 1;
    		ans[i] = 0;
    		int cur = 2;
    		for (int i = 0; i < n; i++) {
    			if (ans[i] == -1) {
    				ans[i] = cur++;
    			}
    		}
    //cout << "!1" << endl;
    		print(ans);
    		return;
    	}
    	if (i != n - 1 && !R[i]) {
			vi ans(n, -1);
    		ans[i + 1] = 1;
    		ans[i] = 0;
    		int cur = 2;
    		for (int i = 0; i < n; i++) {
    			if (ans[i] == -1) {
    				ans[i] = cur++;
    			}
    		}
    //cout << "!1" << endl;
    		print(ans);
    		return;
    	}
    }
    //cout << "!2" << endl;
    vi ans(n, -1);
    ans[0] = 0;
    ans[n - 1] = 1;
    int cur = 2;
    for (int i = 0; i < n; i++) {
    	if (ans[i] == -1) {
    		ans[i] = cur++;
    	}
    }
    print(ans);
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
