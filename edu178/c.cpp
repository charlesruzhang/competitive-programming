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
    string s;
    cin >> s;
    vi a(n);
    int ca = 0;
    int cb = 0;
    if (n == 2) {
    	if (s[0] == 'B') {
    		cout << "Bob" << endl;
    	} else {
    		cout << "Alice" << endl;
    	}
    	return;
    }
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'B') {
    		a[i] = 0;
    		cb++;
    	} else {
    		a[i] = 1;
    		ca++;
    	}
    }
    if (a[n-1] && !(a[0]) && !a[n-2]) {
    	cout << "Bob" << endl;
    } else if (a[n-1] && !a[0]) {
    	cout << "Alice" << endl;
    } else if (a[n-1] && a[0]) {
    	cout << "Alice" << endl;
    } else if (!a[n-1] && cb >= 2) {
    	cout << "Bob" << endl;
    } else {
    	cout << "Alice" << endl;
    }
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
