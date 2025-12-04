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
    int n, f;
    cin >> n >> f;
    vector<tuple<int,int,int>> v;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	int l, r;
    	cin >> l >> r;
    	v.push_back({l, 1, i + 1});
    	v.push_back({r, 0, i + 1});
    	ans += r - l;
    }
    sort(v.begin(), v.end());
    int tot = 0;
    int prev = -1;
    vi res;
    vi used(n+1);
    stack<pii> st;
    for (int i = 0; i < 2 * n; i++) {
    	auto [x, z, idx] = v[i];
    	if (tot == 0) {
    		ans += max(0, x - max(f, prev));
    		while (!st.empty()) {
    			auto [y, w] = st.top();
    			res.push_back(w);
    			st.pop();
    		}
    	}
    	if (x > f && !used[idx]) {
    		if (z == 0) {
    			used[idx] = 1;
    			res.push_back(idx);
    		} else {
    			used[idx] = 2;
    		}
    	} else if (used[idx] == 2) {
    		st.push({x, idx});
    	}
    	if (!z) {
    		tot--;
    	} else {
    		tot++;
    	}
    	prev = x;
    }
    for (int i = 2 * n - 1; i >= 0; i --) {
    	auto [x, z, idx] = v[i];
    	if (!z) continue;
    	if (!used[idx]) res.push_back(idx);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
    	cout << res[i] << " ";
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
