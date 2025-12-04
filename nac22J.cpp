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
int T = 27 * 27 * 27;
vector<pii> dp(T, pii(-1, -1));
void comp() {
	function <pii(int, int)> dfs = [&] (int state, int turn) {
		if (dp[state] != pii(-1, -1)) {
			return dp[state];
		}
		vi val(9);
		int cur = state;
		for (int i = 0; i < 9; i++) {
			val[8 - i] = cur % 3;
			cur /= 3;
		}
		auto check = [&] (int x, int y, int z) {
			if (val[x] != val[y] || val[y] != val[z] || val[z] != val[x]) {
				return -1;
			}
			return val[x];
		};
		vi V;
		V.push_back(check(0, 1, 2));
		V.push_back(check(0, 3, 6));
		V.push_back(check(0, 4, 8));
		V.push_back(check(1, 4, 7));
		V.push_back(check(2, 5, 8));
		V.push_back(check(2, 4, 6));
		V.push_back(check(3, 4, 5));
		V.push_back(check(6, 7, 8));
		int z = *max_element(V.begin(), V.end());
		if (z == 1) {
			return dp[state] = pii(1, 0);
		}
		if (z == 2) {
			return dp[state] = pii(0, 1);
		}
		int u = turn + 1;
		pii ans = {0, 0};
		for (int i = 0; i < 9; i++) {
			if (val[i] == 0) {
				val[i] = u;
				int X = 0;
				for (int j = 0; j < 9; j++) {
					X = X * 3 + val[j];
				}
				auto [x, y] = dfs(X, turn ^ 1);
				ans.first += x;
				ans.second += y;
				val[i] = 0;
			}
		}
		return dp[state] = ans;
	};
	dfs(0, 0);
}
void solve() {
    string s;
    cin >> s;
    int cur = 0;
    for (int i = 0; i < 9; i++) {
    	int z = 0;
    	if (s[i] == 'X') {
    		z = 1;
    	} else if (s[i] == 'O') {
    		z = 2;
    	}
    	cur = cur * 3 + z;
    }
    cout << dp[cur].first << " " << dp[cur].second << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
