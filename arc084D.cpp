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
    vi vis(n, INF);
    vis[1] = 1;
    deque<pii> q;
    q.push_front({1, 1});
    while (!q.empty()) {
    	auto [x, y] = q.front();
    	q.pop_front();
    	if (vis[y] < x) continue;
    	if (y == 0) {
    		cout << x << endl;
    		return;
    	}
    	int z = (10 * y) % n;
    	int w = (y + 1) % n;
    	if (vis[z] > x) {
    		vis[z] = x;
    		q.push_front({x, z});
    	}
    	if (vis[w] > x + 1) {
    		vis[w] = x + 1;
    		q.push_back({x + 1, w});
    	}
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
