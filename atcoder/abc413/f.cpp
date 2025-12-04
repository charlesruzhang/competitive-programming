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
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> q;
    for (int i = 0; i < k; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	grid[x][y] = 0;
    	q.push({0, x, y});
    }
    while (!q.empty()) {
    	auto [d, x, y] = q.top();
    	q.pop();
    	int z = grid[x][y];
    	if (x && y && grid[x-1][y-1] != -1) {
    		if (grid[x][y-1] == -1) {
    			grid[x][y-1] = 1 + max(grid[x-1][y-1], z);
    			q.push({grid[x][y-1], x, y-1});
    		}
    		if (grid[x-1][y] == -1) {
    			grid[x-1][y] = 1 + max(grid[x-1][y-1], z);
    			q.push({grid[x-1][y], x-1, y});
    		}
    	}
    	if (x && y != w - 1 && grid[x-1][y+1] != -1) {
    		if (grid[x][y+1] == -1) {
    			grid[x][y+1] = 1 + max(grid[x-1][y+1], z);
    			q.push({grid[x][y+1], x, y+1});
    		}
    		if (grid[x-1][y] == -1) {
    			grid[x-1][y] = 1 + max(grid[x-1][y+1], z);
    			q.push({grid[x-1][y], x-1, y});
    		}
    	}
    	if (x != h - 1 && y && grid[x+1][y-1] != -1) {
    		if (grid[x][y-1] == -1) {
    			grid[x][y-1] = 1 + max(grid[x+1][y-1], z);
    			q.push({grid[x][y-1], x, y-1});
    		}
    		if (grid[x+1][y] == -1) {
    			grid[x+1][y] = 1 + max(grid[x+1][y-1], z);
    			q.push({grid[x+1][y], x+1, y});
    		}
    	}
    	if (x != h - 1 && y != w - 1 && grid[x+1][y+1] != -1) {
    		if (grid[x][y+1] == -1) {
    			grid[x][y+1] = 1 + max(grid[x+1][y+1], z);
    			q.push({grid[x][y+1], x, y+1});
    		}
    		if (grid[x+1][y] == -1) {
    			grid[x+1][y] = 1 + max(grid[x+1][y+1], z);
    			q.push({grid[x+1][y], x+1, y});
    		}
    	}
    	if (x > 1 && grid[x - 2][y] != -1) {
    		if (grid[x-1][y] == -1) {
    			grid[x-1][y] = 1 + max(grid[x-2][y], z);
    			q.push({grid[x-1][y], x - 1, y});
    		}
    	}
    	if (x < h - 2 && grid[x + 2][y] != -1) {
    		if (grid[x+1][y] == -1) {
    			grid[x+1][y] = 1 + max(grid[x+2][y], z);
    			q.push({grid[x+1][y], x + 1, y});
    		}
    	}

    	if (y > 1 && grid[x][y - 2] != -1) {
    		if (grid[x][y-1] == -1) {
    			grid[x][y-1] = 1 + max(grid[x][y-2], z);
    			q.push({grid[x][y-1], x, y-1});
    		}
    	}

    	if (y < w - 2 && grid[x][y + 2] != -1) {
    		if (grid[x][y+1] == -1) {
    			grid[x][y+1] = 1 + max(grid[x][y+2], z);
    			q.push({grid[x][y+1], x, y+1});
    		}
    	}
    }
    ll summ = 0;
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		summ += max(0, grid[i][j]);
    		cout << grid[i][j] << " ";
    	}
    	cout << endl;
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
