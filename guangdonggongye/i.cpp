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
int query(vi & a) {
	cout << "? " << a.size() << " ";
	for (int x : a) {
		cout << x + 1 << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
    int n, p;
    cin >> n >> p;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	vi d = {i};
    	int res = query(d);
    	a[i] = res;
    }
    vi left(n);
    for (int i = 0; i < n; i++) {
    	left[i] = i;
    }
    while (left.size() >= 2) {
    	int res = query(left);
    	vi x; vi y;
    	for (int z: left) {
    		if (a[z] == res) {
    			x.push_back(z);
    		} else {
    			y.push_back(z);
    		}
    	}
    	int sz = x.size();
    	int l = 0;
    	int r = sz - 1;
    	while (l < r) {
    		int m = (l + r) / 2;
    		vi y2 = y;
    		for (int i = l; i <= m; i++) {
    			y2.push_back(x[i]);
    		}
    		int res2 = query(y2);
    		if (res2 == res) {
    			r = m;
    		} else {
    			l = m + 1;
    		}
    	}
    	vi left2 = y;
    	for (int i = 0; i < sz; i++) {
    		if (i == l) continue;
    		left2.push_back(x[i]);
    	}
    	swap(left2, left);
    }
    cout << "! " << a[left[0]] << endl;
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
