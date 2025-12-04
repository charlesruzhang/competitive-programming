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
    ll cur = 0;
    ll ans = 0;
    stack<pll> st;
    st.push({INF, -1});
    int one = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '0') {
    		int start = i - one;
    		if (i) st.pop();
    		cur += 1ll * (one - 1) * one / 2;
    		for (int j = start; j < i; j++) {
    			st.push({one--, j});
    		}
    		one = 0;
    	} else {
    		one++;
    	}
    	while (st.top().first <= one) {
    		auto [v, j] = st.top();
    		st.pop();
    		auto [v2, j2] = st.top();
    		cur -= 1ll * (j - j2) * v;
    	}
    	auto [v2, j2] = st.top();
    	cur += 1ll * one * (i - one + 1 - j2);
    	st.push({one, i - one + 1});
    	ans += cur + 1ll * (one - 1) * one / 2;
    	//cout << i << " " << ans << " " << cur << endl;
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
