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
    vi a(n), b(n);
    map<int, int> ma;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int c = 0;
    int loc = -1;
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    	ma[a[i]] = b[i];
    	if (a[i] == b[i]) {
    		c++;
    		loc = i;
    	}
    }
    map<int, int> ma2;
    for (int i = 0; i < n; i++) {
    	if (ma[b[i]] != a[i]) {
    		cout << -1 << endl;
    		return;
    	}
    	ma2[a[i]] = i;
    }
    vector<pii> ans;
    if (n % 2) {
    	if (c != 1) {
    		cout << -1 << endl;
    		return;
    	}
    	if (loc != (n - 1) / 2) {
    		swap(a[loc], a[(n - 1) / 2]);
    		swap(b[loc], b[(n - 1) / 2]);
    		ma2[a[loc]] = loc;
    		ma2[a[(n - 1) / 2]] = (n - 1) / 2;
    	 	ans.push_back({loc, (n - 1) / 2});
    	}
    } else {
    	if (c >= 1) {
    		cout << -1 << endl;
    		return;
    	}
    }
    for (int i = 0; i * 2 + 1 < n; i++) {
    	int j = ma2[b[i]];
    	if (j + i != n - 1) {
    		swap(a[n-1-i], a[j]);
    		swap(b[n-1-i], b[j]);
    		ma2[a[n-1-i]] = n-1-i;
    		ma2[a[j]] = j;
    		ans.push_back({n-1-i, j});
    	}
    }	
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
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
