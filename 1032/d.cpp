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
void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }

    vector<pii> ans;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n-1; j++) {
    		if (a[j] > a[j+1]) {
    			swap(a[j], a[j+1]);
    			ans.push_back({1, j});
    		}
    		if (b[j] > b[j+1]) {
    			swap(b[j], b[j+1]);
    			ans.push_back({2, j});
    		}
    	} 
    }
    for (int i = 0; i < n; i++) {
    	if (a[i] > b[i]) {
    		swap(a[i], b[i]);
    		ans.push_back({3, i});
    	}
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans) {
    	cout << x << " " << y + 1 << endl;
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
