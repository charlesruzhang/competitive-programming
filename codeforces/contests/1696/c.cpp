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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int k;
    cin >> k;
    vi b(k);
    for (int i = 0; i < k; i++) {
    	cin >> b[i];
    }
    auto work = [&] (vi& a, vector<pll>& v) {
    	for (int i = 0; i < a.size(); i++) {
    		int cnt = 1;
    		while (a[i] % m == 0) {
    			a[i] /= m;
    			cnt *= m;
    		}
    		if (v.size()) {
    			auto [x, y] = v.back();
    			if (x == a[i]) {
    				v.pop_back();
    				v.push_back({x, y + cnt});
    			} else {
    				v.push_back({a[i], cnt});
    			}
    		} else {
    			v.push_back({a[i], cnt});
    		}
    		//cout << i << " " << cnt << endl;
    	}
    };
    vector<pll> v, w;
    work(a, v); work(b, w);
    if (v==w) {
    	cout << "Yes" << endl;
    } else {
    	cout << "No" << endl;
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
