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
    string s;
    cin >> s;
    vi ans(n);
    int cur = 0;
    int l = cur;
    int r = cur;
    for (int i = 0; i < n - 1; i++) {
    	if (s[i] == '<') {
    		ans[i+1] = l - 1;
    		l--;
    	} else {
    		ans[i+1] = r + 1;
    		r++;
    	}
    }

    for (int i = 0; i < n; i++) {
    	cout << ans[i] - l + 1 << " ";
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
