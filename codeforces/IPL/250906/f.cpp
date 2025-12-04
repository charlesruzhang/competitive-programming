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
    vector<int> a;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	a.push_back(x);
    }
    vector<vector<pii>> ans(n);
    for (int i = 0; i < n; i++) {
    	int prev = -1;
    	auto it = a.begin();
    	int flag = 1;
    	int l = -1;
    	int cnt = 0;
    	int idx = 0;
    	vector<int> b;
    	vi mark(a.size());
    	while (it != a.end()) {
    		if (*it == prev) {
    			cnt++;
    		} else {
    			if (cnt) {
    				int f = 0;

    				if (prev < l) {
    					f |= 1;
    				}
    				if (prev < *it) {
    					f |= 2;
    				}
    				if (f == 3) {
    					for (int j = 0; j < (cnt / 2); j++) {
    						ans[i + j].push_back({prev, idx - cnt + j});
    						ans[i + j].push_back({prev, idx - 1 - j});
    						mark[idx - 1 - j] = mark[idx - cnt + j] = 1;
    					}
    					if (cnt & 1) {
    						ans[i + cnt / 2].push_back({prev, idx - 1 - cnt / 2});
    						mark[idx - 1 - cnt / 2] = 1;
    					}
    				} else if (f == 2) {
    					if (l == -1) {
    						for (int j = 0; j < cnt; j++) {
    							ans[i+j].push_back({prev, idx - j - 1});
    							mark[idx - 1 - j] = 1;
    						}
    					} else {
    						ans[i].push_back({prev, idx - 1});
    						mark[idx - 1] = 1;
    					}
    				} else if (f == 1) {
    					ans[i].push_back({prev, idx - cnt});
    					mark[idx - cnt] = 1;
    				}
    			}
    			cnt = 1;
    			l = prev;
    			prev = *it;
    		}
    		idx++;
    		++it;
    	}
    	if (prev < l) {
	    	for (int j = 0; j < cnt; j++) {
	    		ans[i+j].push_back({prev, idx - j - 1});
	    		mark[idx - 1 - j] = 1;
	    	}
    	}
    	for (int j = 0; j < a.size(); j++) {
    		if (!mark[j]) {
    			b.push_back(a[j]);
    		}
    	}
    	int flag2 = 0;
    	for (int j = 1; j < b.size(); j++) {
    		if (b[j] != b[j-1]) {
    			flag2 = 1;
    			break;
    		}
    	}
    	swap(a, b);
    	if (!flag2) break;
    	if (a.size() == 0) break;
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
    	sort(ans[i].begin(), ans[i].end(), [&](pii a, pii b) {
    		return a.second < b.second;
    	});
    	if (ans[i].size()) maxx = max(maxx, i+1);
    }
    cout << maxx << endl;
    for (int i = 0; i < maxx; i++) {
    	for (int j = 0; j < ans[i].size(); j++) {
    		cout << ans[i][j].first << " ";
    	}
    	cout << endl;
    }
    for (int i = 0; i < a.size(); i++) {
    	cout << a[i] << " ";
    }
    cout << endl;
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
