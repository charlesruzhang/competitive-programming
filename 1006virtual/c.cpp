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
    int n, x;
    cin >> n >> x;
    int bit = 0;
    int cur = 0;
    vi ans(n);
    for (int i = 0; i < n - 1; i++) {
    	cur |= i;
   		if ((cur | x) > x) {
   			ans[i] = x;
   			bit = 1;
   			break;
   		} else {
   			ans[i] = i;
   		}
    }
    if (!bit && ((cur | (n-1)) == x)) {
    	ans[n-1] = n-1;
    } else {
    	ans[n-1] = x;
    }

    for (int i = 0 ; i < n; i++) {
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
