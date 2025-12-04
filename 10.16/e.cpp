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
	    int n, k;
	    cin >> n >> k;
	    string s, t;
	    cin >> s>> t;
	    vi cnta(26);
	    vi cntb(26);
	    for (int i = 0; i < n; i++) {
	    	int x = s[i] - 'a';
	    	int y = t[i] - 'a';
	    	cnta[x]++;
	    	cntb[y]++;
	    }
	    int tot = 0;
	    for (int i = 0; i < 26; i++) {
	    	int z = cnta[i];
	    	tot += (z / k) * k;
	    	z = z % k;
	    	if (z != cntb[i] % k) {
	    		cout << "No" << endl;
	    		return;
	    	}
	    	tot -= (cntb[i] - z);
	    	if (tot < 0) {
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
