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
    int h, w, k;
    cin >> h >> w >> k;
    vvi grid(h, vi(w, -1));
    vvi inq(h, vi(w, 0));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> q;
    for (int i = 0; i < k; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	grid[x][y] = 0;
    }
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		int cnt = 0;
    		if (i && grid[i-1][j] == 0) {
    			cnt++;
    		}
    		if (i != h - 1 && grid[i+1][j] == 0) {
    			cnt++;
    		}
    		if (j && grid[i][j-1] == 0) {
    			cnt++;
    		}
    		if (j != w - 1 && grid[i][j+1] == 0) {
    			cnt++;
    		}
    		if (cnt >= 2 && grid[i][j] != 0) {
    			q.push({1, i, j});
    		}
    	}
    }
    while (!q.empty()) {
    	auto [d, i, j] = q.top();
    	q.pop();
    	int z = grid[i][j];
    	int minn = 1e9;
    	int m2 = 1e9;
    	if (z <= d + 1 && z >= 0) continue;
    	//cout << i << " " << j << endl;
    	if (i && grid[i-1][j] >= 0) {
    		int x = grid[i-1][j];
			if (minn > x) {
				m2 = minn;
				minn = x;
			} else if (m2 > x) {
				m2 = x;
			}
		}
		if (i != h - 1 && grid[i+1][j] >= 0) {
			int x = grid[i+1][j];
			if (minn > x) {
				m2 = minn;
				minn = x;
			} else if (m2 > x) {
				m2 = x;
			}
		}
		if (j && grid[i][j-1] >= 0) {
			int x = grid[i][j-1];
			if (minn > x) {
				m2 = minn;
				minn = x;
			} else if (m2 > x) {
				m2 = x;
			}
		}
		if (j != w - 1 && grid[i][j+1] >= 0) {
			int x = grid[i][j+1];
			if (minn > x) {
				m2 = minn;
				minn = x;
			} else if (m2 > x) {
				m2 = x;
			}
		}
		if (m2 != 1e9) {
			grid[i][j] = m2 + 1;
			if (i && (grid[i-1][j] < 0 || grid[i-1][j] >= m2 + 2)) {
    			q.push({m2 + 1, i - 1, j});
    		}
    		if (i != h - 1 && (grid[i+1][j] < 0 || grid[i+1][j] >= m2 + 2)) {    			
    			q.push({m2 + 1, i + 1, j});
    		}
    		if (j && (grid[i][j-1] < 0 || grid[i][j-1] >= m2 + 2)) {
    			q.push({m2 + 1, i, j - 1});
    		}
    		if (j != w - 1 && (grid[i][j+1] < 0 || grid[i][j+1] >= m2 + 2)) {
    			q.push({m2 + 1, i, j + 1});
    		}
		}
    }
    ll summ = 0;
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		summ += max(0, grid[i][j]);
    		//cout << grid[i][j] << " ";
    	}
    	//cout << endl;
    }
    cout << summ << endl;
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
