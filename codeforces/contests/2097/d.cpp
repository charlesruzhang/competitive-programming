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
    string t;
    cin >> s >> t;
    int x = n;
    if (n % 2) {
    	if (s == t) {
    		cout << "Yes" << endl;
    	} else {
    		cout << "No" << endl;
    	}
    	return;
    }
    while (x % 2 == 0) {
    	x /= 2;
    }
    x *= 2;
    int d = n / x;
    auto f = [&] (string u) {
    	assert(u.size() % 2 == 0 && u.size() % 4 != 0);
    	int half = u.size() / 2;
    	vector<int> newu(half * 2);
    	for (int i = 0; i < half * 2; i++) {
    		newu[i] = u[i] - '0';
    	}
    	int op1 = 0;
    	int op2 = 0;
    	for (int i = 0; i < half; i++) {
    		if (u[i] == u[i + half] && u[i] == '1') {
    			op1 = 1;
    			op2 = 0;
    			break;
    		} else if (u[i] == '0') {
    			break;
    		} else if (u[i+half] == '0') {
    			op1 = 1;
    			op2 = 1;
    			break;
    		}
    	}
    	if (op1) {
    		for (int i = 0; i < half; i++) {
    			newu[i] ^= newu[i+half];
    		}
    	}
    	if (op2) {
    		for (int i = 0; i < half; i++) {
    			newu[i+half] ^= newu[i];
    		}
    	}
    	return newu;
    };
    for (int i = 0; i < d; i++) {
    	if (f(s.substr(x * i, x)) != f(t.substr(x*i, x))) {
    		cout << "No" << endl;
    		return;
    	}
    }
    cout << "Yes" << endl;
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
