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
    int flag = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (a[i]) flag = 1;
    }
    if (!flag) {
    	cout << "NO" << endl;
    	return;
    }
    sort(a.begin(), a.end(), greater<>());
    int i = 0;
    int j = n - 1;
    vi ans;
    ll tot = 0;
    while (i <= j) {
    	if (tot <= 0) {
	    	ans.push_back(a[i]);
	    	tot += a[i];
	    	i++;
    	} else {
	    	ans.push_back(a[j]);
	    	tot += a[j];
	    	j--;
    	}
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
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
