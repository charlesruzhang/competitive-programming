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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll summ = accumulate(a.begin(), a.end(), 0ll);
    if (summ > x) {
    	for (int i = 0; i < n; i++) {
    		cout << a[i] << " ";
    	}
    	cout << endl;
    	return;
    }
    if (summ == x - 1) {
    	int s = 0, y = 0;
    	for (int i = 0; i < n; i++) {
    		if (a[i] == 2) {
    			s++;
    		} else if (a[i] == 0) {
    			y++;
    		}
    	}
    	for (int i = 0; i < y; i++) {
    		cout << 0 << " ";
    	}
    	for (int i = 0; i < s; i++) {
    		cout << 2 << " ";
    	}
    	for (int i = 0; i < n - s - y; i++) {
    		cout << 1 << " ";
    	}
    	cout << endl;
    	return;
    }
    cout << -1 << endl;
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
