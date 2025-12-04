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
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;
    	a[i].second = i+1;
    }
    vector<pii> p(m);
    sort(a.begin(), a.end(), greater<>());
    for (int i = 0; i < m; i++) {
    	cin >> p[i].first;    	
    	p[i].second = i;
    }
    vvi ans(m);
    vector<ll> t(m);
	for (int i = 0; i < n; i++) {
		int best = 0;
		__int128 bestx = 0;
		__int128 besty = 1;
		for (int j = 0; j < m; j++) {
			if (bestx * (t[j] + a[i].first) < besty * (1ll * p[j].first * a[i].first)) {
				bestx = (1ll * p[j].first * a[i].first);
				besty = (t[j] + a[i].first);
				best = j;
			}
		}
		t[best] += a[i].first;
    	ans[p[best].second].push_back(a[i].second);
	}
    	
    for (int i = 0; i < m; i++) {
    	cout << ans[i].size() << " ";
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
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
