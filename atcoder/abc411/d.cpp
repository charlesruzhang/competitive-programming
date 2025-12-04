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
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, string>> qrs(q);
    for (int i = 0; i < q; i++) {
    	int z, p;
    	cin >> z >> p;
    	p--;
    	if (z == 2) {
    		string s;
    		cin >> s;
    		reverse(s.begin(), s.end());
    		qrs[i] = {z, p, s};
    	} else {
    		string s = "";
    		qrs[i] = {z, p, s};
    	}
    }
    int cur = -1;
    string ans = "";
    for (int i = q - 1; i >= 0; i--) {
    	auto [z, p, s] = qrs[i];
    	if (cur == -1 && z == 3) {
    		cur = p;
    		continue;
    	} else if (cur == -1) {
    		continue;
    	}
    	if (z == 1 && p == cur) {
    		cur = -1;
    		continue;
    	}
    	if (z == 2 && p == cur) {
    		ans += s;
    	}
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
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
