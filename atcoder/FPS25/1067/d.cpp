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
    string s, t;
    cin >> s >> t;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	a[i] = s[i] - '0';
    	b[i] = t[i] - '0';
    }
    vector<pii> ans;
    vector<pii> ans2;
    auto work = [&] (vi& a, vector<pii>& ans) {
    	int target = a[0];
	    for (int i = 1; i < n; i++) {
	    	if (a[i] != target) {
	    		int flag = 0;
	    		for (int j = i + 1; j < n; j++) {
	    			if (a[j] == a[i]) {
	    				flag = 1;
	    				ans.push_back({i, j});
	    				for (int k = i; k <= j; k++) {
	    					a[k] ^= 1;
	    				}
	    				break;
	    			}
	    		}
	    		if (!flag) {
	    			if (i != 1) {
	    				ans.push_back({0, i - 1});
	    				ans.push_back({0, i});
	    				a[i] ^= 1;
	    			} else {
	    				ans.push_back({i + 1, n - 1});
	    				ans.push_back({i, n - 1});
	    				a[i] ^= 1;
	    			}
	    			break;
	    		}
	    	}
	    }
	};
	work(a, ans); work(b, ans2);
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << b[i] << " ";
	// }
	// cout << endl;
	// assert(a == b);
	if (a[0] != b[0]) {
		ans.push_back({0, n - 1});
	}
	reverse(ans2.begin(), ans2.end());
	assert(ans.size() + ans2.size() <= 2 * n);
	cout << ans.size() + ans2.size() << endl;
	for (auto [l, r] : ans) {
		cout << l + 1 << " " << r + 1 << endl;
	}
	for (auto [l, r] : ans2) {
		cout << l + 1 << " " << r + 1 << endl;
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
