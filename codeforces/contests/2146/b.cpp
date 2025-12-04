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
    vi cnt(m+1);
    vvi a(n);
    for (int i = 0; i < n; i++) {
    	int sz;
    	cin >> sz;
    	for (int j = 0; j < sz; j++) {
    		int x;
    		cin >> x;
    		cnt[x]++;
    		a[i].push_back(x);
    	}
    }
    for (int i = 1; i <= m; i++) {
    	if (!cnt[i]) {
    		cout << "NO" << endl;
    		return;
    	}
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	int flag = 1;
    	for (int x : a[i]) {
    		if (cnt[x] == 1) {
    			flag = 0;
    		}
    	}
    	if (flag == 1) {
    		ans++;
    	}
    }
    cout << ((ans >= 2) ? "YES" : "NO") << endl;
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
