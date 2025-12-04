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
    int n, m, k;
    cin >> n >> m >> k;
    if (m < n) {
    	cout << -1 << endl;
    	return;
    }
    int cur = 0;
    int prev = 0;
    vi ans(n);
    m -= n;
    for (int i = 0; i < n; i++) {
    	prev++;
    	if (prev > k) {
    		prev -= k;
    	}
    	if (m < cur) {
    		prev = ans[i - m - 1];
    		for (int j = i; j < n; j++) {
    			ans[j] = prev;
    		}
    		m = 0;
    		break;
    	} else {
    		m -= cur;
    		cur = min(cur + 1, k - 1);
    		ans[i] = prev;
    	}
    }
    if (m > 0) {
    	cout << -1 << endl;
    } else {
    	for (int i = 0; i < n; i++) {
    		cout << ans[i] << " ";
    	}
    	cout << endl;
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
