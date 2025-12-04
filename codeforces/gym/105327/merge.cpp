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
    vi x(n);
    for (int i = 0; i < n; i++) {
    	cin >> x[i];
    }
    vi ans(n);
    function <vector<pii>(int, int)> f = [&] (int l, int r) {
    	if (l == r) {
    		vector<pii> a(1, pii(x[l], l));
    		return a;
    	}
    	int m = (l + r) / 2;
    	vector<pii> a = f(l, m);
    	vector<pii> b = f(m + 1, r);
    	int i = 0;
    	vector<pii> c;
    	for (int j = 0; j < b.size(); j++) {
    		while (i < a.size() && a[i].first > b[j].first) {
    			c.push_back(a[i]);
    			i++;
    		}
    		ans[b[j].second] += i;
    		c.push_back(b[j]);
    	}
    	for (int j = i; j < a.size(); j++) {
    		c.push_back(a[j]);
    	}
    	return c;
    };
    f(0, n - 1);
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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
