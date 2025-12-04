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
    string s;
    cin >> s;
    int l = 0;
    int r = 0;
    vl suff;
    suff.push_back(0);
    vl pref;
    pref.push_back(0);
    for (int i = n - 1; i >= 0; i--) {
    	if (s[i] == '<') {
    		r++;
    		suff.push_back(suff.back() + i);
    	}
    }
    for (int i = 0; i < n; i++) {
    	if (s[i] == '>') {
    		pref.push_back(pref.back() + i);
    	}
    }
    for (int i = 0; i < n; i++) {
    	if (s[i] == '<') {
    		r--;
    	}
    	ll ans = 0;
    	//cout << i << " " << l << " " << r << endl;
    	if (s[i] == '<') {
    		ans = i;
    		if (l > r) {
    			int x = r + 1;
    			ans -= 2 * (pref[l] - pref[l-x]);
    			ans += 2 * (suff[r]);
    			ans += n;
    		} else {
    			int x = l;
    			ans -= 2 * (pref[l]);
    			ans += 2 * (suff[r] - suff[r - l]);
    			ans -= -1;
    		}
    	} else {
    		ans = -i;
    		if (l >= r) {
    			int x = r;
    			ans -= 2 * (pref[l] - pref[l-x]);
    			ans += 2 * (suff[r]);
    			ans += n;
    		} else {
    			int x = l + 1;
    			ans -= 2 * (pref[l]);
    			ans += 2 * (suff[r] - suff[r - x]);
    			ans -= -1;
    		}
    	}

    	if (s[i] == '>') {
    		l++;
    	}
    	cout << ans << " ";
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
