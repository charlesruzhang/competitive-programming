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
    int x = k / (1 << n);
    vi ans(1 << n, x);
    k = k % (1 << n);
    vi mark(1 << n);
    int tot = 0;
    for (int i = n; i >= 0; i--) {
    	int cur = 0;
    	if (tot == k) {
    		break;
    	}
    	while (cur < (1 << n)) {
    		if (ans[cur] == x) {
    			ans[cur]++;
    			tot++;
    			if (tot == k) {
    				break;
    			}
    		}
    		cur += (1 << i);
    	}
    }
    cout << ((k) ? 1 : 0) << endl;
    for (int i = 0; i < (1 << n); i++) {
    	cout << ans[i] << " ";
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
