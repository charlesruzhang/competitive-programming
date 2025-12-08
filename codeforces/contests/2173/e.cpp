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
pii query(int u, int v) {
	cout << "? " << u + 1 << " " << v + 1 << endl;
	int x, y;
	cin >> x >> y;
	x--; y--;
	return pii(x, y);
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi loc(n+1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	loc[a[i]] = i;
    }
    for (int i = 1; i <= n / 2; i++) {
    	while (loc[i] != i - 1) {
    		auto res = query(loc[i], i - 1);
    		cnt++;
    		auto [x, y] = res;
    		loc[a[x]] = y;
    		loc[a[y]] = x;
    		swap(a[x], a[y]);	
    	}
    	while (loc[n - i + 1] != n - i) {
    		auto res = query(loc[n - i + 1], n - i);
    		cnt++;
    		auto [x, y] = res;
    		loc[a[x]] = y;
    		loc[a[y]] = x;
    		swap(a[x], a[y]);
    		while (loc[i] != i - 1) {
    			auto res2 = query(loc[i], i - 1);
	    		cnt++;
	    		auto [x, y] = res2;
	    		loc[a[x]] = y;
	    		loc[a[y]] = x;
	    		swap(a[x], a[y]);
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	assert(a[i] == i + 1);
    }
    cout << "!" << endl;
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
