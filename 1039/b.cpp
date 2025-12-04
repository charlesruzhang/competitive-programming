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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi ans;
    int l = 0;
    int r = n - 1;
    int dir = 0;
    while (l <= r) {
    	if (a[l] <= a[r]) {
    		if (dir) {
    			ans.push_back(1);
    			l++;
    		} else {
    			ans.push_back(0);
    			r--;
    		}
    	} else {
    		if (!dir) {
    			ans.push_back(1);
    			l++;
    		} else {
    			ans.push_back(0);
    			r--;
    		}
    	}
    	dir = 1 - dir;
    }
    for (int i = 0; i < n; i++) {
    	char c = (ans[i] == 1) ? 'L' : 'R';
    	cout << c;
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
