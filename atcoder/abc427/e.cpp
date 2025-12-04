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
    int n, m;
    cin >> n >> m;
    vvi vs(n, vi(m));
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0;j < m; j++) {
    		vs[i][j] = (s[j] == '#' ? 1 : s[j] == '.' ? 0 : 2);
    		if (vs[i][j] == 2) {
    			x = i; y = j;
    			vs[i][j] = 0;
    		}
    	}
    }
    queue<pair<int, vvi>> q;
    q.push({0, move(vs)});
    set<ll> S;
    while (!q.empty()) {
    	auto [d, A] = q.front();
    	q.pop();
    	if (x + 1 >= n || A[x + 1][y] != 1) {
    		vvi B(n, vi(m));
    		int tot = 0;
    		ll cur = 0;
    		for (int i = 0; i < n; i++) {
    			for (int j = 0; j < m; j++) {
    				B[i][j] = (i + 1 < n ? A[i + 1][j] : 0);
    				tot += B[i][j];
    				cur = cur * MOD + B[i][j];
    			}
    		}
    		if (tot == 0) {
    			cout << d + 1 << endl;
    			return;
    		}
    		if (S.find(cur) == S.end()) {
    			q.push({d + 1, move(B)});
    		    S.insert(cur);
    		}
    	}
    	if (x - 1 < 0 || A[x - 1][y] != 1) {
    		vvi B(n, vi(m));
    		int tot = 0;
    		ll cur = 0;
    		for (int i = 0; i < n; i++) {
    			for (int j = 0; j < m; j++) {
    				B[i][j] = (i - 1 >= 0 ? A[i - 1][j] : 0);
    				tot += B[i][j];
    				cur = cur * MOD + B[i][j];
    			}
    		}
    		if (tot == 0) {
    			cout << d + 1 << endl;
    			return;
    		}
    		if (S.find(cur) == S.end()) {
    			q.push({d + 1, move(B)});
    		    S.insert(cur);
    		}
    	}
    	if (y + 1 >= m || A[x][y+1] != 1) {
    		vvi B(n, vi(m));
    		int tot = 0;
    		ll cur = 0;
    		for (int i = 0; i < n; i++) {
    			for (int j = 0; j < m; j++) {
    				B[i][j] = (j + 1 < m ? A[i][j+1] : 0);
    				tot += B[i][j];
    				cur = cur * MOD + B[i][j];
    			}
    		}
    		if (tot == 0) {
    			cout << d + 1 << endl;
    			return;
    		}
    		if (S.find(cur) == S.end()) {
    			q.push({d + 1, move(B)});
    		    S.insert(cur);
    		}
    	}
    	if (y - 1 < 0 || A[x][y-1] != 1) {
    		vvi B(n, vi(m));
    		int tot = 0;
    		ll cur = 0;
    		for (int i = 0; i < n; i++) {
    			for (int j = 0; j < m; j++) {
    				B[i][j] = (j - 1 >= 0 ? A[i][j-1] : 0);
    				tot += B[i][j];
    				cur = cur * MOD + B[i][j];
    			}
    		}
    		if (tot == 0) {
    			cout << d + 1 << endl;
    			return;
    		}
    		if (S.find(cur) == S.end()) {
    			q.push({d + 1, move(B)});
    		    S.insert(cur);
    		}
    	}
    }
    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
