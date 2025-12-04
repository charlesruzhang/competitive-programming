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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vvi a(4, vi(8));
    map<char, int> ma;
    ma['C'] = 0;
    ma['D'] = 1;
    ma['H'] = 2;
    ma['S'] = 3;
    
    for (int i = 0; i < 2 * n; i++) {
    	string t;
    	cin >> t;
    	int z = t[0] - '2';
    	char y = t[1];
    	a[ma[y]][z] = 1;
    }
    vvi par(8, vi(4));
    vector<pii> ans;
    vector<int> waitlist;
    for (int i = 0; i < 4; i++) {
    	if (i == ma[s[0]]) continue;
    	int j = 0;
    	int prev = -1;
    	while (j < 8) {
    		if (a[i][j]) {
    			if (prev != -1) {
    				ans.push_back({i * 8 + prev, i * 8 + j});
    				prev = -1;
    			} else {
    				prev = j;
    			}
    		}
    		j++;
    	}
    	if (prev != -1) {
    		waitlist.push_back(i * 8 + prev);
    	}
    }
    vi vec;
    int x = ma[s[0]];
    for (int i = 0; i < 8; i++) {
    	if (a[x][i]) {
    		vec.push_back(x * 8 + i);
    	}
    }
    if (waitlist.size() > vec.size()) {
    	cout << "IMPOSSIBLE" << endl;
    	return;
    }
    for (int i = 0; i < waitlist.size(); i++) {
    	ans.push_back({waitlist[i], vec[i]});
    }
    for (int i = waitlist.size(); i < vec.size(); i+=2) {
    	ans.push_back({vec[i], vec[i+1]});
    }
    for (int i = 0; i < ans.size(); i++) {
    	int y = ans[i].first % 8;
    	int z = ans[i].first / 8;
    	char c;
    	if (z == 0) {
    		c = 'C';
    	} else if (z == 1) {
    		c = 'D';
    	} else if (z == 2) {
    		c = 'H';
    	} else if (z == 3) {
    		c = 'S';
    	}
    	cout << y + 2 << c << " ";
    	y = ans[i].second % 8;
    	z = ans[i].second / 8;
    	if (z == 0) {
    		c = 'C';
    	} else if(z == 1) {
    		c = 'D';
    	} else if (z == 2) {
    		c = 'H';
    	} else if (z == 3) {
    		c = 'S';
    	}
    	cout << y + 2 << c << endl;
    }
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
