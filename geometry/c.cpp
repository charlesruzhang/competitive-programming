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
    vi x(n), y(n);
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
    	int flag = 1;
    	for (int j = 0; j < n; j++) {
    		int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    		if (dist > k) {
    			flag = -1;
    			break;
    		}
    	}
    	ans = max(ans, flag);
    }
    cout << ans << endl;
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
