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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<vector<bool>> vb(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		vb[i][j] = s[j] - '0';
    	}
    }
    ll maxx = -MAXX;
    vi maxv(m, 0);
    for (int i = 0; i < (1 << n); i++) {
    	vector<pii> x(m);
    	for (int j = 0; j < m; j++) {
    		x[j].second = j;
    	}
    	ll score = 0;
    	for (int k = 0; k < n; k++) {
    		bool b  = (i / (1 << k)) % 2;
    		for (int j = 0; j < m; j++) {
    			if (b) x[j].first += vb[k][j];
    			else x[j].first -= vb[k][j];
    		}
    		if (b) score -= a[k];
    		else score += a[k];
    	}
    	sort(x.begin(), x.end(), greater<>());
    	for (int j = 0; j < m; j++) {
    		score += x[j].first * (m - j);
    	}
    	if (maxx < score) {
    		maxx = score;
    		for (int j = 0; j < m; j++) {
    			maxv[x[j].second] = m - j;
    		}
    	}
    }
    for (int i = 0; i < m; i++) {
    	cout << maxv[i] << " ";
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
