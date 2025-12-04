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
    int n, m;
    cin >> n >> m;
    int maxx = -1;
    for (int i = 0; i < n; i++) {
    	int l;
    	cin >> l;
    	vi freq(l+2);
    	for (int j = 0; j < l; j++) {
    		int x;
    		cin >> x;
    		freq[min(x,l+1)]++;
    	}
    	int minn = -1;
    	for (int j = 0; j <= l+1; j++) {
    		if (!freq[j] && minn == -1) {
    			minn = j;
    		} else if (!freq[j]) {
    			maxx = max(maxx, j);
    			break;
    		}
    	}
    }
    ll ans;
    if (m <= maxx) {
    	ans = (m + 1) * 1ll * maxx;	
    } else {
    	ans = (maxx + 1) * 1ll * maxx + (maxx+1+m) * 1ll * (m - maxx) / 2;
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
