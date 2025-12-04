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
int t(int x) {
	cout << "throw " << x + 1 << endl;
	int res;
	cin >> res;
	return res;
}
void s(int x) {
	cout << "swap " << x + 1 << endl;
}
void solve() {
    int n;
    cin >> n;
    vi a(n, -1);
    vi b(n + 2, 0);
    vi hist;
    for (int i = n - 2; i >= 0; i-=2) {
    	if (b[i+2] == b[i+3]) {
    		int res = t(i);
    		if (res != b[i+2] + 1) {
    			a[i+1] = 1;
    		} else {
    			a[i+1] = 2;
    		}
    		b[i+1] = b[i+2] + 1;
    		s(i); hist.push_back(i);
    		res = t(i);
    		if (res != b[i+2] + 1) {
    			a[i] = 1;
    		} else {
    			a[i] = 2;
    		}
    		b[i] = res;
    	} else {
    		int res = t(i+1);
    		if (res == b[i+2] + 1) {
    			a[i] = 1;
    		} else {
    			a[i] = 2;
    		}
    		s(i); hist.push_back(i);
    		res = t(i+1);
    		if (res == b[i+2] + 1) {
    			a[i+1] = 1;
    		} else {
    			a[i+1] = 2;
    		}
    		b[i+1] = res;
    		if (a[i] == 1) {
    			b[i] = b[i+1] + 1;
    		} else {
    			b[i] = b[i+2] + 1;
    		}
    	}
    }
    if (a[0] == -1) {
    	assert(n > 2);
    	if (b[1] == b[2]) {
    		assert(a[1] == 2);
    		s(0); hist.push_back(0);
    		int res = t(1);
    		a[0] = 2;
    		if (res == b[2]) {
    			a[1] = 2;
    		} else {
    			a[1] = 1;
    		}
    	} else {
    		int res = t(0);
    		if (res == b[1] + 1) {
    			a[0] = 1;
    		} else {
    			a[0] = 2;
    		}
    	}
    }
    reverse(hist.begin(), hist.end());
    for (int v : hist) {
    	swap(a[v], a[v+1]);
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
    	cout << a[i] << " ";
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
