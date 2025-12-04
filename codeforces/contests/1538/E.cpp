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
    map<string, ll> hc;
    map<string, string> pref;
    map<string, string> suff;
    for (int i = 0 ; i < n; i++) {
    	string s;
    	char c;
    	cin >> s >> c;
    	if (c == ':') {
    		string x;
    		cin >> c >> x;
    		int count = 0;
    		if (x.size() >= 5 && x.substr(1, 4) == "haha") count++; 
    		if (x.size() >= 4 && x.substr(0, 4) == "haha") count++;
    		hc[s] = count;
    		string p = x.substr(0, min((int) x.size(), 3));
    		pref[s] = p;
    		p = x.substr(max(0, (int) x.size() - 3));
    		suff[s] = p;
    		if (i == n - 1) cout << count << endl;
    	} else {
    		string x, y;
    		cin >> x >> c >> y;
    		ll count = hc[x] + hc[y];
    		string comp = suff[x] + pref[y];
    		for (int j = 0; j < ((int) comp.size() - 3); j++) {
    			if (comp.substr(j, 4) == "haha") {
    				count++;
    			}
    		}
    		string p = pref[x];
    		string q = suff[y];
    		if (p.size() < 3) {
    			p = comp.substr(0, min((int) comp.size(), 3));
    		}
    		if (q.size() < 3) {
    			q = comp.substr(max(0, (int) comp.size() - 3));
    		}
    		hc[s] = count;
    		pref[s] = p;
    		suff[s] = q;
    		if (i == n - 1) {
    			cout << count << endl;
    			return;
    		}
    	}
    }
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
