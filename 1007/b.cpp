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
    int n;
    cin >> n;
    vi ans(n+1);
    int prev = 1;
    for (int i = 1; i <= n; i++) {
    	ans[i] = i;
    }
    ll summ = 0;
    for (int i = 1; i <= n; i++) {
    	ll x = summ +  ans[i];
    	if (trunc(sqrt(x)) * trunc(sqrt(x)) == x) {
    		if (i == n) {
    			cout << -1 << endl;
    			return;
    		}
    		swap(ans[i], ans[i+1]);
    	}
    	summ += ans[i];
    }
    for (int i = 1; i <= n; i++) {
    	if (ans[i] != i) cout << ans[i] << " ";
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
