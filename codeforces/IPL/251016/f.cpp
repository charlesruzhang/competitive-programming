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
    string s, t;
    cin >> s >> t;
    int n = t.size();
    vi p = {131, 137};
    vl cur = {0, 0};
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 2; j++) {
    		cur[j] = cur[j] * p[j] + t[i];
    	}
    }
    vvl P(n + 2, vl(2, 1));
    for (int i = 1; i <= n + 1; i++) {
    	for (int j = 0; j < 2; j++) {
    		P[i][j] = P[i-1][j] * p[j];
    	}
    }
    vvl C(n + 2, vl(2));
    for (int i = 0; i < n + 1; i++) {
    	for (int j = 0; j < 2; j++) {
    		C[i+1][j] = C[i][j] * p[j] + s[i];
    	}
    }
    vi ans;
    for (int i = 0; i < n + 1; i++) {
    	vl X(2);
    	for (int j = 0; j < 2; j++) {
    		X[j] = C[n+1][j] - C[i+1][j] * P[n- i][j] + C[i][j] * P[n - i][j];
    	}
    	if (X[0] == cur[0] && X[1] == cur[1]) {
    		ans.push_back(i);
    	}
    }
    cout << ans.size() << endl;
    for (int x : ans) {
    	cout << x + 1 << " ";
    }
    cout << endl;
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
