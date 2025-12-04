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
    vvi a(n);
    vvi vs;
    for (int i = 0; i < n; i++) {
    	int m;
    	cin >> m;
    	a[i].resize(m);
    	for (int j = 0; j < m; j++) {
    		if (vs.size() <= j) {
    			vs.push_back({});
    		}
    		cin >> a[i][j];
    		vs[j].push_back(i);
    	}
    }
    int i = 0;
    vi ans;
    vi s;
    for (int i = 0; i < n; i++) {
    	s.push_back(i);
    }
    for (int i = 0; i < vs.size(); i++) {
    	int minn = 1e9+1;
    	vi t;
    	for (int j = 0; j < s.size(); j++) {
    		if (a[s[j]].size() == i) {
    			vi u;
    			for (int z = 0; z < vs[i].size(); z++) {
    				u.push_back(vs[i][z]);
    			}
    			swap(s, u);
    			break;
    		}
    	}
    	for (int j = 0; j < s.size(); j++) {
    		if (minn > a[s[j]][i]) {
    			minn = a[s[j]][i];
    			t.clear();
    			t.push_back(s[j]);
    		} else if (minn == a[s[j]][i]) {
    			t.push_back(s[j]);
    		}
    	}
    	ans.push_back(minn);
    	swap(s, t);
    }
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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
