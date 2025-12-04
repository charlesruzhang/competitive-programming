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
    int n, k;
    cin >> n >> k;
    vector<pii> v;
    for (int i = 0; i < k ; i++) {
    	int l, r;
    	cin >> l >> r;
    	v.push_back({r - l + 1, l});
    }
    sort(v.begin(), v.end(), greater<>());
    vi p(n+1);
    int root = v[0].second;
    for (int i = 0; i < k; i++) {
    	for (int j = 1; j < v[i].first; j++) {
    		p[v[i].second + j] = v[i].second + j - 1;
    	}
    	p[v[i].second] = root;
    }
    p[root] = 0;
    if (k > 1 && v[0].first == v[1].first) {
    	if (v[0].first - v.back().first < 2) {
    		cout << "IMPOSSIBLE" << endl;
    		return;
    	}
    	p[v.back().second] = v[0].second + 1;
    }
    for (int i = 1; i <= n; i++) {
    	cout << p[i] << " ";
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
