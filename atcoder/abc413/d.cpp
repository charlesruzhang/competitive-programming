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
    int n;
    cin >> n;
    vi a(n);
    vector<pii> b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	b[i] = {abs(a[i]), i};
    }
    sort(b.begin(), b.end());
    int flag = 0;
    for (int i = 1; i < n; i++) {
    	if (b[i].first != b[i-1].first) {
    		flag = 1;
    		break;
    	}
    }
    if (!flag) {
    	int cnt = 0;
    	for (int i = 0; i < n; i++) {
    		if (a[i] < 0) {
    			cnt++;
    		}
    	}
    	if (cnt == n || cnt * 2 == n || cnt == 0 || (n % 2 == 1 && abs(cnt * 2 - n) == 1)) {
    		cout << "Yes" << endl;
    	} else {
    		cout << "No" << endl;
    	}
    	return;
    }
    for (int i = 1; i < n - 1; i++) {
    	auto [x1, y1] = b[i];
    	auto [x0, y0] = b[i-1];
    	auto [x2, y2] = b[i+1];
    	if (1ll * a[y1] * a[y1] != 1ll * a[y0] * a[y2]) {
    		cout << "No" << endl;
    		return;
    	}
    }
    cout << "Yes" << endl;
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
