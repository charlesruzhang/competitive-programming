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
    vi b(n);
    for (int i = 0; i < n; i++) {
    	if (i % 2 == 0) cin >> a[i];
    	else cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
    	if (i % 2 == 1) cin >> a[i];
    	else cin >> b[i];
    }
    set<int> s;
    set<int> x;
    set<int> y;
    for (int i = n - 1; i >= 0; i--) {
    	if (x.find(b[i]) != x.end()) {
    		cout << i + 1 << endl;
    		return;
    	}
    	if (y.find(a[i]) != y.end()) {
    		cout << i + 1 << endl;
    		return;
    	}
    	if (a[i] == b[i]) {
    		cout << i + 1 << endl;
    		return;
    	}
    	x.insert(a[i]);
    	y.insert(b[i]);
    	if (s.find(a[i]) != s.end() || s.find(b[i]) != s.end()) {
    		cout << i + 1 << endl;
    		return;
    	}
    	if (i != n - 1) {
    		s.insert(a[i+1]);
    		s.insert(b[i+1]);
    	} 
    }
    cout << 0 << endl;
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
