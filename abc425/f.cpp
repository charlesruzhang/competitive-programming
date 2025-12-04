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
    vector<vector<char>> vs(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		vs[i][j] = s[j];
    	}
    }
    queue<pii> q;
    auto F = [&] (int i, int j) {
    	if (vs[i][j] == '#') return 0; 
		int cnt = 0;
		if (i && vs[i-1][j] == '#') cnt++;
		if (j && vs[i][j-1] == '#') cnt++;
		if (i != n - 1 && vs[i+1][j] == '#') cnt++;
		if (j != m - 1 && vs[i][j+1] == '#') cnt++;
		return cnt;
    };
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (F(i, j) == 1) {
    			q.push({i, j});
    		}
    	}
    }
    while (!q.empty()) {
    	queue<pii> q2;
    	vector<pii> wait;
    	while (!q.empty()) {
	    	auto [i, j] = q.front();
	    	q.pop();
	    	if (vs[i][j] == '#') continue;
	    	wait.push_back({i, j});
	    }
	    for (auto [i, j] : wait) {
	    	vs[i][j] = '#';
	    }
	    for (auto [i, j] : wait) {
	    	if (i && F(i-1, j) == 1) q2.push({i - 1, j});
	    	if (j && F(i, j-1) == 1) q2.push({i, j-1});
	    	if (i != n - 1 && F(i+1, j) == 1) q2.push({i + 1, j});
	    	if (j != m - 1 && F(i, j+1) == 1) q2.push({i, j + 1});
	    }
	    swap(q, q2);
    }
    
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		tot += (vs[i][j] == '#');
    	}
    }
    cout << tot << endl;
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
