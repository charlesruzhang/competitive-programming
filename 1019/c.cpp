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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++) {
    	if (a[i] > k) {
    		b[i] = 1;
    	}
    }
    int one = 0;
    int idx = -1;
    vi pref(n+1);
    for (int i = 0; i < n; i++) {
    	if (b[i]) {
    		one++;
    	} else {
    		one--;
    	}
    	pref[i+1] = one;
    }
    int count = 0;
    if (pref[n] < 0) {
    	cout << "YES" << endl;
    	return;
    }
    for (int i = 0; i < n - 1; i++) {
    	if (count == 0) {
	    	if (pref[i+1] < 0) {
	    		if (b[i+1] == 0) {
	    			cout << "YES" << endl;
	    			return;
	    		}
	    	} else if (pref[i+1] == 0) {
	    		count++;
	    		idx = i;
	    	}
	    } else {
	    	if (pref[i+1] <= pref[idx+1]) {
	    		cout << "YES" << endl;
	    		return;
	    	}
	    }
    }
    count = 0;
    for (int i = n - 1; i >= 1; i--) {
    	if (count == 0) {
	    	if (pref[n] - pref[i] < 0) {
	    		if (b[i-1] == 0) {
	    			cout << "YES" << endl;
	    			return;
	    		}
	    	} else if (pref[n] - pref[i] == 0) {
	    		count++;
	    		idx = i;
	    	}
	    } else {
	    	if (pref[i] >= pref[idx]) {
	    		cout << "YES" << endl;
	    		return;
	    	}
	    }
    }
    if (count == 0) {
    	cout << "NO" << endl;
    	return;
    }
    for (int i = 0; i < idx - 1; i++) {
    	if (pref[i+1] <= 0) {
    		cout << "YES" << endl;
    		return;
    	}
    }
    cout << "NO" << endl;
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
