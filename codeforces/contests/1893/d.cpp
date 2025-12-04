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
    int n, m;
    cin >> n >> m;
    vi cnt(n+1);
    for (int i = 0; i < n; i++) {
    	int c;
    	cin >> c;
    	cnt[c]++;
    }
    vector<array<int, 3>> a(m);
    for (int i = 0; i < m; i++) {
    	cin >> a[i][1];
    }
    for (int i = 0; i < m; i++) {
    	cin >> a[i][0];
    	a[i][2] = i;
    }
    priority_queue<pii> Q;
    for (int i = 1; i <= n; i++) {
    	if (cnt[i]) {
    		Q.push({cnt[i], i});
    	}
    }
    sort(a.begin(), a.end(), greater<>());
    vvi ans(m);
    int tot = n;
    vi pref(n+1);
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
    	while (a[i][0] > j) {
    		j++;
    		pref[j] = pref[j-1] + (i + 1);
    	}
    }
    while (j <= n) {
    	pref[j] = n;
    	j++;
    }
    for (int i = 0; i < m; i++) {
    	priority_queue<pii> pq;
    	auto [req, sz, idx] = a[i];
    	ans[idx].resize(sz);
    	tot -= sz;
    	auto it = lower_bound(pref.begin(), pref.end(), tot);
    	int extra = *it - tot;
    	int low = it - pref.begin();
    	int high = low + (extra > 0);
    	for (int j = 0; j < req; j++) {
    		int target = sz / req + (j < (sz % req));
    		pq.push({target, j});
    	}
    	vector<pii> wait;
    	int used = 0;
    	while (pq.size()) {
    		auto [target, j] = pq.top();
    		pq.pop();
    		if (Q.size() == 0) {
    			cout << -1 << endl;
    			return;
    		}
    		auto [c, k] = Q.top();
    		Q.pop();
    		int t = (used > extra ? low : high);
    		if (c < target) {
    			pq.push({target - c, j + c * req});
    		} else if (c > target) {
    			wait.push_back({c - target, k});
    		}
    		int cur = j;

    		for (int z = 0; z < min(c, target); z++) {
    			ans[idx][cur] = k;
    			cur += req;
    		}
    	}
    }
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < ans[i].size(); j++) {
    		cout << ans[i][j] << " ";
    	}
    	cout << endl;
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
