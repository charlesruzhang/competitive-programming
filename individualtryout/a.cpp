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
    int n, m, k;
    cin >> n >> m >> k;
    if (n * m % k) {
    	cout << "IMPOSSIBLE" << endl;
    	return;
    }
    int x = n * m / k;
    int g = gcd(n, x);
    int h = x / g;
    char lette = 'A';
    vector<vector<char>> ans(n, vector<char>(m));
    for (int i = 0; i < n / g; i++) {
    	for (int j = 0; j < m / h; j++) {
    		//i * g + j * h;
    		for (int z = 0; z < g; z++) {
    			for (int y = 0; y < h; y++) {
    				ans[i * g + z][j * h + y] = lette;
    			}
    		}
    		++lette;
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cout << ans[i][j];
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
