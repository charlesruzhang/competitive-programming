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
int query(int i, int j) {
	cout << "? " << i + 1 << " " << j + 1 << endl;
	int res;
	cin >> res;
	res--;
	return res;
}
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
    	cout << "! " << 0 << endl;
    	return;
    } 
    vi a;
    int o = 0;
    for (int i = 1; i < n; i++) {
    	int x = query(o, i);
    	o = x;
    }
    for (int i = 0; i < n; i++) {
    	if (i != o) {
    		a.push_back(i);
    	}
    }
    vi ans;
    while (a.size()) {
    	int sz = a.size();
    	int prev = a[0];
    	vi b;
    	for (int i = 1; i < sz; i++) {
    		int x = query(prev, a[i]);
    		if (x == o) {
    			b.push_back(a[i]);
    		} else {
    			prev = x;
    		}
    	}
    	ans.push_back(prev);
    	swap(a, b);
    }
    cout << "! " << ans.size() << " ";
    for (int x: ans) {
    	cout << x + 1 << " ";
    }
    cout << endl;
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
