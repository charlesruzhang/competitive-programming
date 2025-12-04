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
    vi a(n);
    vi cnt(n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }
    vi pref(n + 1);
    for (int i = 1; i <= n; i++) {
    	pref[i] = pref[i-1] + cnt[i];
    }
    vector<pii> q;
    for (int i = 0; i < m; i++) {
    	int l, r;
    	cin >> l >> r;
    	q.push_back({l, r});
	}
	sort(q.begin(), q.end());
	vector<int> ranges;
	int prev = -1;
	int prevl = -1;
	for (int i = 0; i < m; i++) {
		auto [l, r] = q[i];
		if (l > prev) {
			if (prev != -1) {
				ranges.push_back(prev - prevl + 1);
			}
			prevl = l;
			prev = r;
		} else {
			prev = max(prev, r);
		}
	}

	ranges.push_back(prev - prevl + 1);
	sort(ranges.begin(), ranges.end());
	vi dp(n + 1);
	dp[0] = 1;
	for (int i = 0; i < ranges.size(); i++) {
		vi ndp = dp;
		for (int j = n; j >= ranges[i]; j--) {
			ndp[j] |= dp[j - ranges[i]];
		}
		swap(ndp, dp);
	}
	vi ans(n + 1);
	for (int i = 1; i <= n; i++) {
		int minn = pref[i-1];
		int maxx = pref[i];
		bool t = 0;
		for (int j = minn; j <= maxx; j++) {
			t |= dp[j];
		}
		cout << t;
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
