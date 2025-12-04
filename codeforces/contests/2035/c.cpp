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
    if (n == 5) {
    	cout << 5 << endl;
    	cout << "2 1 3 4 5" << endl;
    	return;
    }
    int z = n % 2;
    n -= z;
    if ((n & (n - 1)) == 0) {
    	n -= 2;
    	z += 2;
    }
    vi ans;
    int y = 1;
    while (y < n) {
    	y *= 2;
    }
    y /= 2;
    for (int i = 1; i <= n; i++) {
    	if (i == y - 1 || i == y) {
    		continue;
    	}
    	ans.push_back(i);
    }
    ans.push_back(y);
    ans.push_back(y-1);
    for (int i = n + 1; i <= n + z; i++) {
    	ans.push_back(i);
    }
    int d = 0;
    for (int i = 0; i < ans.size(); i++) {
    	if (i % 2 == 0) {
    		d &= ans[i];
    	} else {
    		d |= ans[i];
    	}
    }
    cout << d << endl;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] << " ";
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
