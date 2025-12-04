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
int query(vi& a, int x) {
	cout << "? " << x + 1 << " " << a.size() << " ";
	for (int y : a) {
		cout << y + 1 << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
    int n;
    cin >> n;
    int l = 0;
    int r = 2 * n - 2;
    vi left;
    for (int i = 0; i < n; i++) {
    	left.push_back(i);
    }
    vi both;
    while (l < r) {
    	int m = (l + r + 1) / 2;
    	vi L;
    	vi R;
    	for (int i = l; i < m; i++) {
    		L.push_back(i);
    	}
    	for (int i = m; i <= r; i++) {
    		R.push_back(i);
    	}
    	int ls = m - l;
    	int rs = r - m + 1;
    	vi resL(left.size());
    	vi resR(left.size());
    	int j = 0;
    	for (int x : left) {
    		resL[j] = query(L, x);
    		resR[j] = query(R, x);
    		j++;
    	}
    	vi bl, br;
    	for (int x : both) {
    		int res = query(L, x);
    		if (res) {
    		    bl.push_back(x);
    			ls--;
    		} else {
    		    br.push_back(x);
    			rs--;
    		}
    	}
    	vi both2;
    	for (int i = 0; i < left.size(); i++) {
    		if (resL[i] && resR[i]) {
    			both2.push_back(left[i]);
    			ls--;
    			rs--;
    		}
    	}
    	vi left2;
    	if (ls % 2 == 1) {
    		for (int i = 0; i < left.size(); i++) {
    			if (!resR[i]) {
    				left2.push_back(left[i]);
    			}
    		}
    		for (int x : bl) {
    		    both2.push_back(x);
    		}
    		r = m - 1;
    	} else {
    		for (int i = 0; i < left.size(); i++) {
    			if (!resL[i]) {
    				left2.push_back(left[i]);
    			}
    		}
    		for (int x : br) {
    		    both2.push_back(x);
    		}
    		l = m;
    	}
    	swap(left, left2);
    	swap(both, both2);
    }
    if (left.size() != 1) {
    	cout << "??" << endl;

    }
    cout << "! " << left[0] + 1 << endl;
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
