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
	ll minn = MAXX;
	if (n == 1) {
		cout << "7" << endl;
		return;
	}
    for (int i = 1; i <= 1000; i++) {
    	for (int j = 1; j <= 1000; j++) {
    		int x = i * (i + 1) / 2;
    		int y = j * (j + 1) / 2;
    		if (x + y > n) continue;
    		if (x + y == n) {
    			for (int k = 0; k < i; k++) {
    				s += '7';
    			}
    			s+='1';
    			for (int k = 0; k < j; k++) {
    				s += '7';
    			}
    			cout << s << endl;
    			return;
    		}
    		int z = (n - x - y) * 2;

    		int w = trunc(sqrt(z));
    		if (w * (w + 1) == z) {
    			if (j % 3 == 2) swap(i, j);
    			if (j % 3 == 2) swap(j, w);
    			if (j % 3 == 2) assert(0);
    			for (int k = 0; k < i; k++) {
    				s += '7';
    			}
    			s+='1';
    			for (int k = 0; k < j; k++) {
    				s += '7';
    			}
    			s+='1';
    			for (int k = 0; k < w; k++) {
    				s += '7';
    			}
    			cout << s << endl;
    			return;
    		}
    	}
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
