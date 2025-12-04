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
	int x;
	cin >> x;
	return x;
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi freq(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	freq[a[i]]++;
    }
    int p = -1;
    int q = -1;
    for (int i = 1; i <= n; i++) {
    	if (!freq[i]) {
    		p = i;
    		for (int j = 0; j < n; j++) {
    			if (p - 1 != j && a[p-1] != a[j]) {
    				q = j + 1;
    				break;
    			}
    		}
    		break;
    	}
    }
    if (p != -1) {
    	assert(q!=-1);
    	int r = query(p, q);
    	if (r) {
    		cout << "! B" << endl;
    		return;
    	} else {
    		cout << "! A" << endl;
    	}
    } else {
    	int pp = -1;
    	int qq = -1;
    	for (int i = 0; i < n; i++) {
    		if (a[i] == 1) {
    			pp = i + 1;
    		}
    		if (a[i] == n) {
    			qq = i + 1;
    		}
    	}
    	int r1 = query(pp, qq);
    	int r2 = query(qq, pp);
    	if (r1 > (n-1) || r2 > (n- 1)) {
    		cout << "! B" << endl;
    		return; 
    	} else if (r1 == (n - 1) && r2 == (n-1)) {
    		cout << "! B" << endl;
    	} else {
    		cout << "! A" << endl;
    	}
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
