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
    int n;
    cin >> n;
    double a = 0, b = 0, c = 0;
    double pa = 0, pb = 0, pc = 0;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	if (s[0] == 'Y') {
    		if (s[1] == 'Y') {
    			a++;
    		}
    		if (s[2] == 'Y') {
    			b++;
    		}
    		if (s[3] == 'Y') {
    			c++;
    		}
    		c1++;
    	} else {
    		if (s[1] == 'Y') {
    			pa++;
    		}
    		if (s[2] == 'Y') {
    			pb++;
    		}
    		if (s[3] == 'Y') {
    			pc++;
    		}
    		c2++;
    	}
    }
    if (1ll * a * c2 >= 1ll * pa * c1) {
    	cout << "Not Effective" << endl;
    } else {
    	cout << setprecision(10) << 100 * (1ll * pa * c1 - 1ll * a * c2) / (double)(1ll * pa * c1) << endl;
    }
    if (1ll * b * c2 >= 1ll * pb * c1) {
    	cout << "Not Effective" << endl;
    } else {
    	cout << setprecision(10) << 100 * (1ll * pb * c1 - 1ll * b * c2) / (double)(1ll * pb * c1) << endl;
    }
    if (1ll * c * c2 >= 1ll * pc * c1) {
    	cout << "Not Effective" << endl;
    } else {
    	cout << setprecision(10) << 100 * (1ll * pc * c1 - 1ll * c * c2) / (double)(1ll * pc * c1) << endl;
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
