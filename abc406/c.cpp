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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int dir = 0;
    int cnt = 0;
    vector<pii> v;
    for (int i = 1; i < n; i++) {
    	if (a[i] < a[i - 1] ) {
    		if (dir == -1) {
    			v.push_back({cnt, 1});
    			cnt = 0;
    		}
    		cnt++;
    		dir = 1;
    	} else {
    		if (dir == 1) {
    			v.push_back({cnt, -1});
    			cnt = 0;
    		}
    		cnt++;
    		dir = -1;
    	}
    }
    v.push_back({cnt, dir});
    ll tot = 0;
    // for (int i = 0; i < v.size(); i++) {
    // 	cout << v[i].first << " ";
    // }
    // cout << endl;
    for (int i = 1; i < ((int) v.size()) - 1; i++) {
    	auto [x, y] = v[i];
    	if (y == -1) {
    		tot += 1ll * v[i-1].first * v[i+1].first;
    	}
    }
    cout << tot << endl;
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
