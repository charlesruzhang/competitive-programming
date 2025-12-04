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
vi dist(1 << 14, 1e9);
vvi dp(1 << 7, vi(1 << 14, 1e9));
void print(int x) {
	vi ans;
	while (x) {
		ans.push_back(x % 2);
		x/=2;
	}
	reverse(ans.begin(), ans.end());
	for (int y : ans) {
		cout << y;
	}
	cout << endl;
}
void comp() {
	queue<int> q;
	int x = 0;
	x |= (1 << 0);
	x |= (1 << 2);
	x |= (1 << 4);
	x |= (1 << 6);

	x |= (1 << 7);
	x |= (1 << 8);
	x |= (1 << 11);
	x |= (1 << 12);
	q.push(x);
	dist[x] = 0;
	while (!q.empty()) {
		int u = q.front();
		//print(u);
		q.pop();
		int v = u;
		int w = 0;
		for (int i = 0; i < 7; i++) {
			int d;
			d = (v & (1 << (i + 7))) & ((v & (1 << i)) << 7);
			w |= d;
			w |= (v & (1 << i));
		}
		if (dist[w] == 1e9) {
			q.push(w);
			dist[w] = dist[u] + 1;
		}
		w = 0;
		for (int i = 0; i < 7; i++) {
			int d;
			d = (v & (1 << (i + 7))) | ((v & (1 << i)) << 7);
			w |= d;
			w |= (v & (1 << i));
		}
		if (dist[w] == 1e9) {
			q.push(w);
			dist[w] = dist[u] + 1;
		}
		w = 0;
		for (int i = 0; i < 7; i++) {
			int d;
			d = ((v & (1 << (i + 7))) >> 7) ^ (v & (1 << i));
			w |= d;
			w |= (v & (1 << (i + 7)));
		}
		if (dist[w] == 1e9) {
			q.push(w);
			dist[w] = dist[u] + 1;
		}
		w = 0;
		for (int i = 0; i < 7; i++) {
			int d;
			int z = (i >= 4) ? 0 : (1 << i);
			d = z ^ (v & (1 << i));
			w |= d;
			w |= (v & (1 << (i + 7)));
		}
		if (dist[w] == 1e9) {
			q.push(w);
			dist[w] = dist[u] + 1;
		}
	}
	for (int i = 0; i < (1 << 14); i++) {
		for (int j = 0; j < (1 << 7); j++) {
			int x = 0;
			for (int z = 0; z < 7; z++) {
				if ((1 << z) & j) {
					x |= (i & (1 << z));
					x |= (i & (1 << (z + 7)));
				}
			}
			dp[j][x] = min(dp[j][x], dist[i]);
		}
	}
}
void solve() {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    vi ma(7, -1);
    for (int i = 0; i <= 30; i++) {
    	int x = ((a & (1 << i)) >= 1) << 1;
    	int y = ((b & (1 << i)) >= 1);
    	int z = ((m & (1 << i)) >= 1) << 2;
    	int w = ((c & (1 << i)) >= 1) << 1;
    	int t = ((d & (1 << i)) >= 1);
    	if (x == 0 && y == 0 && z == 0) {
    		if (w || t) {
    			cout << -1 << endl;
    			return;
    		}
    	} else {
    		if (ma[7 - (x + y + z)] == -1) {
    			ma[7 - (x + y + z)] = (w << 6) + t;
    		} else if (ma[7 - (x + y + z)] != (w << 6) + t) {
    			cout << -1 << endl;
    			return;
    		}
    	}
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < 7; i++) {
    	if (ma[i] != -1) {
    		x |= (1 << i);
    		y |= (ma[i] << i);
    		//cout << "? " << i << " " << ma[i] << endl;
    	}
    }
    if (dp[x][y] == 1e9) {
    	cout << -1 << endl;
    	return;
    }
    cout << dp[x][y] << endl;
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
