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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<pii> em;
    vvi visited(h, vi(w));
    vvi d(h, vi(w, 1e9));
    vector<vector<char>> dir(h, vector<char>(w, '#'));
    for (int i = 0; i < h; i++) {
    	cin >> s[i];
    	for (int j = 0; j < w; j++) {
    		if (s[i][j] == 'E') {
    			em.push_back({i , j});
    		}
    		if (s[i][j] == '#') {
    			visited[i][j] = 1;
    		}
    	}
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> q;
    for (int i = 0; i < em.size(); i++) {
    	q.push({0, em[i].first, em[i].second});
    	visited[em[i].first][em[i].second] = 1;
	}
    while (!q.empty()) {
    	auto [z, x, y] = q.top();
    	d[x][y] = z;
    	q.pop();

    	if (x && visited[x-1][y]) {
    		if (d[x-1][y] == z - 1) {
    			dir[x][y] = '^';
    		}
    	}
    	if (x != h - 1 && visited[x+1][y]) {
    		if (d[x+1][y] == z - 1) {
    			dir[x][y] = 'v';
    		}
    	}
    	if (y && visited[x][y-1]) {
    		if (d[x][y-1] == z - 1) {
    			dir[x][y] = '<';
    		}
    	}
    	if (y != w - 1 && visited[x][y+1]) {
    		if (d[x][y+1] == z - 1) {
    			dir[x][y] = '>';
    		}
    	}

    	if (x && !visited[x-1][y]) {
    		visited[x-1][y] = 1;
    		q.push({z + 1, x - 1, y});
    	}
    	if (x != h - 1 && !visited[x+1][y]) {
    		visited[x+1][y] = 1;
    		q.push({z + 1, x + 1, y});
    	}
    	if (y && !visited[x][y-1]) {
    		visited[x][y-1] = 1;
    		q.push({z + 1, x, y - 1});
    	}
    	if (y != w - 1 && !visited[x][y+1]) {
    		visited[x][y+1] = 1;
    		q.push({z + 1, x, y + 1});
    	}
    }
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		if (s[i][j] == 'E') cout << 'E';
    		else cout << dir[i][j];
    	}
    	cout << endl;
    }
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
