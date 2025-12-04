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
int query(vi &a) {
	cout << "? " << a.size() << " ";
	for (int v : a) {
		cout << v + 1 << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}
int query(vi & a, int l, int r) {
	cout << "? " << r - l + 1 << " ";
	for (int i = l; i <= r; i++) {
		cout << a[i] + 1 << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
    int n;
    cin >> n;
    vi x(n);
    for (int i = 0; i < n; i++) {
    	x[i] = i;
    }
    int l = 0;
    int r = n - 1;
    int left = -1;
    int right = -1;
    int res = query(x, l, r);
    if (!res) {
    	left = n-1;
    	right = 0;
    } else {
    	while (1) {
    		if (l + 1 == r) {
    			left = l;
    			right = r;
    			break;
    		}
    		int m = (l + r) / 2;
    		int z = query(x, l, m);
    		if (z) {
    			r = m;
    		} else {
    			z = query(x, m + 1, r);
    			if (z) {
    				l = m + 1;
    			} else {
    				z = query(x, m, m+1);
    				if (z) {
    					left = m;
    					right = m + 1;
    				} else {
    					left = m + 1;
    					right = m;
    				}
    				break;
    			}
    		}
	    }
    }
    vi ans(n);

    int cur = n - 2;
    int done = 0;
    int off = 0;
    while (1) {
    	vi a;
    	for (int i = 0; i + off < min(n, off + 250); i++) {
    		a.push_back(i+off);
    	}
    	vi b;
    	for (int v : a) {
    		b.push_back(left);
    		b.push_back(left);
    		b.push_back(v);
    	}
    	int cnt = query(b);
    	if (cnt * 2 >= a.size()) {
    		int z = (a.size() - cnt) * 2;
    		int cur = a[0];
    		vi c;
    		for (int v : a) {
    			c.push_back(left);
    			c.push_back(v);
    		}
    		for (int i = 0; i < z; i++) {
    			c.push_back(right);
    		}
    		int l = 0;
    		int r = c.size() - 1;
    		int prev = query(c, l, r);
    		for (int y = r - 2, k = 0; k < (a.size() - cnt); y -= 2, k++) {
    			int now = query(c, l, y);
    			int diff = prev - now - 2;
    			prev = now;
    			for (int j = 0; j < diff; j++) {
    				ans[cur + j] = 1;
    			}
    			ans[cur + diff] = 0;
    			cur += diff + 1;
    		}
    		for (int k = cur; k <= a.back(); k++) {
    			ans[k] = 1;
    		}
    	} else {
    		int z = cnt * 2;
    		int cur = a.back();
    		vi c;
    		for (int i = 0; i < z; i++) {
    			c.push_back(left);
    		}
    		for (int v : a) {
    			c.push_back(v);
    			c.push_back(right);
    		}
    		int l = 0;
    		int r = c.size() - 1;
    		int prev = query(c, l, r);
    		for (int y = l + 2, k = 0; k < cnt; y += 2, k++) {
    			int now = query(c, y, r);
    			int diff = prev - now - 2;
    			prev = now;
    			for (int j = 0; j < diff; j++) {
    				ans[cur - j] = 0;
    			}
    			ans[cur - diff] = 1;
    			cur -= diff + 1;
    		}
    		for (int k = cur; k >= a[0]; k--) {
    			ans[k] = 0;
    		}
    	}
    	off += 250;
    	if (off >= n) {
    		break;
    	}
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
    	cout << ((ans[i]) ? ')' : '(');
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
