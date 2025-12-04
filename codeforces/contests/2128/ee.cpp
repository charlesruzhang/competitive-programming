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
    int n, k;
    n = 5;
    std::mt19937 rng(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> rr(1, n);
    k = rr(rng);
    vi a(n);
    for (int i = 0; i < n; i++) {
    	a[i] = rr(rng);
    }
    int l = 1;
    int r = n;
    vector<pii> ans(n+1);
    auto check = [&] (int m) {
    	vi P(n), maxx(n+1, 0), idx(n+1, -1);
    	for (int i = 0; i < n; i++) {
    		P[i] = (a[i] >= m) ? 1 : -1;
    	}
    	int cur = 0;
    	for (int i = 0; i < n; i++) {
    		cur += P[i];
    		if (maxx[i] > cur) {
    			idx[i+1] = i;
    			maxx[i+1] = cur;
    		} else {
    			idx[i+1] = idx[i];
    			maxx[i+1] = maxx[i];
    		}
    		if (i + 1 >= k) {
    			if (cur - maxx[i+1-k] >= 0) {
    				ans[m] = {idx[i+1-k] + 1, i};
    				return true;
    			}
    		}
    	}
    	return false;
    };
    while (l < r) {
    	int m = (l + r + 1) / 2;
    	if (check(m)) {
    		l = m;
    	} else {
    		r = m - 1;
    	}
    }
    int maxx = 0;
    auto med = [&] (int l, int r) {
	    int x = l;
	    int y = r;
	    vi vv;
	    for (int i = x; i <= y; i++) {
	    	vv.push_back(a[i]);
	    }
	    sort(vv.begin(), vv.end());
	    int tar = vv.size() / 2;
	    maxx = max(maxx, vv[tar]);
	    return vv[tar];
    };
    for (int i = 0; i < n; i++) {
    	for (int j = i + k - 1; j < n; j++) {
    		med(i, j);
    	}
    }
    if (maxx != l) {
    	for (int i = 0; i < n; i++) {
    		cout << a[i] << " ";
    	}
    	cout << endl;
    	cout << maxx << " " << l << endl;
    }
    assert(maxx == l);
    if (med(ans[l].first, ans[l].second) != l) {
    	for (int i = 0; i < n; i++) {
    		cout << a[i] << " ";
    	}
    	cout << endl;
    	cout << maxx << " " << l << " " << k << endl;
    	cout << ans[l].first << " " << ans[l].second << endl;
    }
    assert(med(ans[l].first, ans[l].second) == l);
    //cout << l << " " << ans[l].first + 1 << " " << ans[l].second + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    t = 10000;
    while (t--) {
        solve();
    }
    return 0;
}
