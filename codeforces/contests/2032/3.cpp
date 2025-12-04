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
int query(int a, int b) {
	cout << "? " << a << " " << b << endl;
	int r;
	cin >> r;
	return r;
}
void solve() {
    int n;
    cin >> n;
    int s = 2;
    vi p(n, 0);
    while (1) {
    	int r = query(1, s);
    	if (!r) break;
    	s++;
    }
    p[s] = 1;
    int cur = 2;
    int t = s + 1;
    while (t < n) {
    	int r = query(cur, t);
    	if (!r) {
    		p[t] = cur;
    		t++;
    	}
    	cur++;
    }
    cout << "! ";
    for (int i = 1; i < n; i++) {
    	cout << p[i] << " ";
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
