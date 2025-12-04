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
    cin >> n >> k;
    string s;
    cin >> s;
    int minn = 1;
    int maxx = n;
    vi ans(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '1') {
    		ans[i] = minn++;
    		cnt++;
    		if (cnt >= k) {
    			cout << "NO" << endl;
    			return;
    		}
    	} else {
    		cnt = 0;
    		ans[i] = maxx--;
    	}
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
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
