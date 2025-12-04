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
	    vector<string> s(n);
	    for (int i = 0; i < n; i++) {
	    	cin >> s[i];
	    }
	    for (int i = 0; i < n; i++) {
	    	if (s[i].size() == 1) {
	    		cout << "YES" << endl;
	    		return;
	    	} else if (s[i].size() == 2) {
	    		if (s[i][0] == s[i][1]) {
	    			cout << "YES" << endl;
	    			return;
	    		}
	    	} else if (s[i].size() == 3 && s[i][0] == s[i][2]) {
	    		cout << "YES" << endl;
	    		return;
	    	}
	    }
	    multiset<int> t;
	    function <int(int)> f = [&] (int i) {
			if (s[i].size() == 2) {
	    		int z = (s[i][0] - 'a') * 26 + (s[i][1] - 'a');
	    		return z;
	    	}
	    	int z = 1000 + (s[i][0] - 'a') * 676 + (s[i][1] - 'a') * 26 + (s[i][2] - 'a');
	    	return z;
	    };
	    for (int i = 0; i < n; i++) {
	    	t.insert(f(i));
	    }
	    for (int i = 0; i < n; i++) {
	    	t.erase(f(i));
	    	if (s[i].size() == 2) {
	    		int w = 26 * (s[i][1] - 'a') + (s[i][0] - 'a');
	    		if (t.find(w) != t.end()) {
	    			cout << "YES" << endl;
	    			return;
	    		}
	    		for (int j = 0; j < 26; j++) {
	    			if (t.find(1000 + j * 676 + w) != t.end()) {
	    				cout << "YES" << endl;
	    				return;
	    			} 
	    		}
	    	} else {
	    		int w = 1000 + (s[i][2] - 'a') * 676 + (s[i][1] - 'a') * 26 + (s[i][0] - 'a');
	    		if (t.find(w) != t.end()) {
	    			cout << "YES" << endl;
	    			return;
	    		}
	    		w = 26 * (s[i][1] - 'a') + (s[i][0] - 'a');
	    		if (t.find(w) != t.end()) {
	    			cout << "YES" << endl;
	    			return;
	    		}
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
