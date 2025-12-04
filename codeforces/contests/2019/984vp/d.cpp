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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		a[i][j] = s[j] - '0';
    	}
    }
    int tot = 0;
    int startx = 0;
    int starty = 0;
    int l = 0;
    int r = m-1;
    int u = 0;
    int d = n-1;
    int curx = startx;
    int cury = starty;
    vector<pii> dir = {pii(0, 1), pii(1, 0), pii(-1, 0), pii(0, -1)};
    int idx = 0;
    int ans = 0;
    while (tot < n * m) {
    	int p = 0;
    	do {	
    		if (a[curx][cury] == 1) p = 1;
    		if (a[curx][cury] == 5 && p == 1) p = 2;
    		if (a[curx][cury] == 4 && p == 2) p = 3;
    		if (a[curx][cury] == 3 && p == 3) p = 0, ans++;
    		curx += dir[idx].first;
    		cury += dir[idx].second;
    	} while (curx != startx || cury != starty);
    } 
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
