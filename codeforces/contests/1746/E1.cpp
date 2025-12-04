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
int query(vi& b) {
	cout << "? " << b.size() << " ";
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	string res;
	cin >> res;
	return (res == "YES");
}
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
    	cout << "! 1" << endl;
    	string x;
    	cin >> x;
    	return;
    }
    vi a(n);
    for (int i = 0; i < n; i++) {
    	a[i] = i + 1;
    }
    auto F = [&] (vi& a, vi& b) {
    	for (int B: b) {
    		a.push_back(B);
    	}
    };
    while (a.size() > 2) {
    	int m = a.size();
    	int x = m / 3;
    	int y = 2 * m / 3;
    	vi b, c, d;
    	for (int i = 0; i < x; i++) {
    		b.push_back(a[i]);
    	}
    	for (int i = x; i < y; i++) {
    		c.push_back(a[i]);
    	}
    	for (int i = y; i < m; i++) {
    		d.push_back(a[i]);
    	}
    	int r1 = query(b);
    	if (!r1) {
    		int r2 = query(b);
    		if (r2) {
    			int r3 = query(c);
    			if (r3) {
    				F(b, c);
    				swap(a, b);
    			} else {
    				F(b, d);
    				swap(a, b);
    			}
    		} else {
    			F(c, d);
    			swap(a, c);
    		}
    	} else {
    		int r2 = query(c);
    		if (r2) {
    			F(b, c);
    			swap(a, b);
    		} else {
    			F(b, d);
    			swap(a, b);
    		}
    	}
    }
    int x = a[0];
    int y = a[1];
    cout << "! " << x << endl;
    string res;
    cin >> res;
    if (res == ":)") {
    	return;
    } else {
    	cout << "! " << y << endl;
    	cin >> res;
    	return;
    }
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
