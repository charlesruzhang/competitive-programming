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
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int xx = 0; int yy =0;
    map<pii, vector<int>> m;
    vi xr(n+1, 0);
    vi yr(n+1, 0);
    m[pii(0,0)].push_back(0);
    map<char, int> cm;
    cm['U'] = 0;
    cm['R'] = 1;
    cm['D'] = 2;
    cm['L'] = 3;
    for (int i = 0; i < n; i++) {
    	xx+= dx[cm[s[i]]];
    	yy+= dy[cm[s[i]]];
    	xr[i+1] = xx;
    	yr[i+1] = yy;
    	m[pii(xx,yy)].push_back(i+1);
    }
    while (q--) {
    	int x, y, l, r;
    	cin >> x >> y >> l >> r;
    	int tarx = xr[l-1] + xr[r] - x;
    	int tary = yr[l-1] + yr[r] - y;
    	int ll = 0;
    	int rr = m[pii(tarx, tary)].size() - 1;
    	int done = 0;
    	if (rr != -1) {
	    	while (ll < rr) {
	    		int mm = (ll + rr + 1) / 2;
	    		int mv = m[pii(tarx, tary)][mm];
	    		if (mv <= r && mv >= l) {
	    			cout << "YES" << endl;
	    			done = 1;
	    			break;
	    		} else if (mv > r) {
	    			rr = mm - 1;
	    		} else {
	    			ll = mm;
	    		}
	    	}
	    	if (ll == rr) {
	    		if (m[pii(tarx, tary)][ll] <= r && m[pii(tarx, tary)][ll] >= l) {
	    			cout << "YES" << endl;
	    			done = 1;
	    			continue;
	    		}
	    	}
	    } 
	    if (!done) {
	    	int ss = m[pii(x,y)].size();
	    	if (ss == 0) {
	    		cout << "NO" << endl;
	    		continue;
	    	}
	    	if (m[pii(x,y)].back() >= r || (m[pii(x,y)][0] <= l-1)) {
	    		cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
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
