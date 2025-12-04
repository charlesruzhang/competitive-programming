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
    int q;
    cin >> q;
    vector<vector<array<int, 3>>> V(n);
    vi ans(q);
    for (int i = 0; i < q; i++) {
    	int l, r, x;
    	cin >> l >> r >> x;
    	r--; l--;
    	V[r].push_back({l, x, i});
    }
    vvi dp(4096, vi(13, -1));
    vvi ndp = dp;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 4096; j++) {
    		for (int k = 1; k <= 12; k++) {
    			ndp[j][k] = max(dp[j^a[i]][k-1], ndp[j][k]);
    			ndp[j][k] = max(dp[j][k], ndp[j][k]);
    		}
    	}
    	ndp[a[i]][1] = i;
    	swap(ndp, dp);
    	for (auto [l, x, id]: V[i]) {
    		int done = 0;
    		for (int j = 1; j <= 12; j++) {
    			if (dp[x][j] >= l) {
    				ans[id] = j;
    				done = 1;
    				break;
    			}
    		}
    		if (!done) {
    			ans[id] = 0;
    		}
    	}
    }
    for (int x: ans) {
    	cout << x << " ";
    }
    cout << endl;
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
