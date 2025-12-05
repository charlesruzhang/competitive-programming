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
    string s;
    multiset<pll> S;
    while (1) {
    	cin >> s;
    	if (s == "!") break;
    	ll cur = 0;
    	int n = s.size();
    	for (int i = 0; i < n; i++) {
    		if (s[i] == '-') {
    			pll x = {cur, 0};
    			cur = 0;
    			S.insert(x);
    		} else {
    			cur = 10 * cur + s[i] - '0';
    		}
    	}
    	S.insert({cur, 2});
    }
    ll x;
    while (1) {
    	cin >> x;
    	if (x < 0) break;
    }
    ll cur = 0;
    ll ans = 0;
    for (auto [x, y]: S) {
    	if (y == 0) {
    		if (cur == 0) ans-=x;
    		cur--;
    	} else if (y == 2) {
    		if (cur == -1) ans+=x+1;
    		cur++;
    	}//cout << x << " " << y << endl;
    }
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
