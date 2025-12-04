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
int query(int x) {
	cout << "? " << x + 1 << endl;
	int res;
	cin >> res;
	return res;
}
void solve(int Z) {
    int n, k;
    cin >> n >> k;
    if (n == 2 * k) {
        cout << "! " << k << " " << k << endl;
        return;
    }
    vi a(k), b(k);
    for (int i = 0; i < k; i++) {
    	a[i] = query(i);
    }
    for (int i = n-1; i >= n-k; i--) {
    	b[i % k] = query(i);
    }
    int flag = 1;
    int idx = -1;
    for (int i = 0; i < k; i++) {
    	if (a[i] != b[i]) {
    		flag = 0;
    		idx = i;
    		break;
    	}
    }
    if (flag) {
    	cout << "! -1" << endl;
    	return;
    }
    int l = 0;
    int r = (n - idx - 1) / k - 1;
    while (l < r) {
    	int m = (l + r + 1) / 2;
    	if (query(m * k + idx) == a[idx]) {
    		l = m;
    	} else {
    		r = m - 1;
    	}
    }
    int prev = 0;
    for (int i = l * k + idx; i <= (l + 1) * k + idx; i++) {
    	if (i == n - k) {
    		if (!prev) {
    			cout << "! " << i << " " << n - i << endl;
    		} else {
    			cout << "! -1" << endl;
    		}
    		return;
    	}
    	int res = query(i);
    	if (res != a[i % k]) {
    		if (!prev || i == k) {
    			cout << "! " << i << " " << n - i << endl;
    		} else {
    			cout << "! -1" << endl;
    		}
    		return;
    	} else {
    		if (res == b[i % k]) {
    			prev = 1;
    		} else {
    			prev = 0;
    		}
    	}
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
   	for (int i = 0; i < t; i++) {
        solve(i);
   	}
    
    return 0;
}
