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
    int n, k;
    cin >> n >> k;
    vl p(n);
    vector<pair<ll, int>> s;
    for (int i = 0; i < n; i++) {
    	cin >> p[i];
    	s.push_back({p[i], i});
    }
    sort(s.begin(), s.end());
    vi d(n);
    for (int i = 0; i < n; i++) {
    	cin >> d[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
    	ll x;
    	cin >> x;
    	int cnt = 0;
    	int dir = 0;
    	ll cur = x;
    	ll offset = 0;
    	int flag = 0;
    	int id = -1;
    	for (int j = 0; j < n; j++) {
    		if (s[j].first >= x) {
    			id = j;
    			break;
    		}
    	}
    	if (id == -1) {
    		cout << "YES" << endl;
    		continue;
    	}
    	while (cnt <= n * n) {
    		if (!dir) {
    			if (id == n) {
    				cout << "YES" << endl;
    				flag = 1;
    				break;
    			}
    			auto [y, idx] = s[id];
    			if ((offset + y - cur) % k == d[idx]) {
    				cur = y;
    				dir = 1;
    				offset = d[idx];
    				id--;
    			} else {
    				offset += y - cur + 1;
    				cur = y + 1;
    				id++;
    			}
    		} else {
    			if (id == -1) {
    				cout << "YES" << endl;
    				flag = 1;
    				break;
    			}
    			auto [y, idx] = s[id];

    			if ((offset + cur - y) % k == d[idx]) {
    				cur = y + 1;
    				dir = 0;
    				offset = d[idx] + 1;
    				id++;
    			} else {
    				offset += cur - y;
    				cur = y;
    				id--;
    			}
    		}
    		cnt ++;
    	 	//cout << cnt << endl;
    	 	//cout << offset << "  " << cur << " " << dir << endl;
    	}
    	if (!flag) cout << "NO" << endl;
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
