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
void solve() {
    string s;
    cin >> s;
    int first = -1;
    int n = s.size();
    for (int i = 0; i < n; i++) {
    	if (s[i] == '0') {
    		first = i;
    		break;
    	}
    }
    if (first == -1) {
    	cout << 1 << " " << n << " " << 1 << " " << 1 << endl;
    	return;
    }
    string maxx = "";
    int idx = -1;
    for (int i = 0; i < first; i++) {
    	string t;
    	for (int j = 0; j < first; j++) {
    		t += s[j];
    	}
    	for (int j = first; j < n; j++) {
    		char c = s[j];
    		char d = s[i + j - first];
    		if (c == d) {
    			t += '0';
    		} else {
    			t += '1';
    		}
    	}
    	if (maxx < t) {
    		maxx = t;
    		idx = i;
    	}
    }
    assert(idx != -1);
    cout << 1 << " " << n << " ";
    cout << idx + 1 << " " << idx + n - first << endl;
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
