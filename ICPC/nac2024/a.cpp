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
    vector<pii> a(n);
    vi ans(5e6+5, INF);
    vi ans2(5e6+5, INF);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first >> a[i].second;
    }
    int m = n / 2;
    int m2 = n - m;
    
    vector<pii> prev;
    prev.push_back({0, 0});
    for (int i = 0; i < m; i++) {
    	vector<pii> now;
    	for (auto [u, v] : prev) {
    		now.push_back({u, v + a[i].second});
    		now.push_back({u + a[i].first, v});
    	}
    	swap(now, prev);
    }
    for (auto [x, y] : prev) {
    	ans[x] = min(ans[x], y);
    }
    prev.clear();
    prev.push_back({0, 0});
    for (int i = 0; i < m2; i++) {
    	vector<pii> now;
    	for (auto [u, v] : prev) {
    		now.push_back({u, v + a[i + m].second});
    		now.push_back({u + a[i + m].first, v});
    	}
    	swap(now, prev);
    }
    for (auto [x, y] : prev) {
    	ans2[x] = min(ans2[x], y);
    }
    for (int i = 1; i <= 5e6; i++) {
    	ans[i] = min(ans[i], ans[i-1]);
    	ans2[i] = min(ans2[i], ans2[i-1]);
    }
    int l = 0;
    int r = 5e6+1;
    while (l < r) {
    	int mid = (l + r) / 2;
    	int flag = 1;
    	int minn = INF;
    	for (int i = 0; i <= mid; i++) {
    		minn = min(minn, ans[i] + ans2[mid - i]);
    	}
    	if (minn > mid) {
    		l = mid + 1;
    	} else {
    		r = mid;
    	}
    }
    cout << l << endl;
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
