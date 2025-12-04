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
    int n, k;
    cin >> n >> k;
    multiset<int> S;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	S.insert(a[i]);
    }
    vector<pii> s(k);
    for (int i = 0; i < k; i++) {
    	cin >> s[i].first;
    	s[i].second = i;
    }
    sort(s.begin(), s.end());
    vvi ans(k);
    int last = k - 1;
    for (int i = 0; i < k - 1; i++) {
    	auto it = S.begin();
    	int mo = s[i].first;
    	vvi dp(mo + 1, vi(mo, -1));
    	dp[0][0] = 0;
    	int done = 0;
    	while (it != S.end()) {
    		vvi ndp = dp;
    		int x = *it;
    		int flag = 0;
    		for (int k = 1; k <= mo; k++) {
    			for (int l = 0; l < mo; l++) {
    				if (ndp[k][(l + x) % mo] == -1 && dp[k - 1][l] >= 0) {
    					ndp[k][(l + x) % mo] = x;
    					if (k == mo && (l + x) % mo == 0) {
    						flag = 1;
    						break;
    					}
    				} 
    			}
    		}
    		if (flag) {
    			vi rem;
    			int cur = 0;
    			int z = mo;
    			while (z > 0) {
    				int x = ndp[z][cur];
    				z--;
    				cur = (cur + mo - (x % mo)) % mo;
    				rem.push_back(x);
    			} 
    			int idx = s[i].second;
    			assert(rem.size() == mo);
    			for (int x : rem) {
    				S.erase(S.find(x));
    				ans[idx].push_back(x);
    				//cout << mo << " : " << x << endl;
    			}
    			done = 1;
    			break;
    		}
    		++it;
    		swap(dp, ndp);
    	}
    	if (!done) {
    		if (last != -1) {
    			assert(false);
    		}
    		last = i;
    	}
    }
    assert(last == k - 1);
    int special = -1;
    if (last != -1) {
    	int sz = s[last].first;
    	int idx = s[last].second;
    	ll tot = 0;
    	for (int x : S) {
    		tot += x;
    		ans[idx].push_back(x);
    	}
    	special = sz - (tot % sz);
    	ans[idx].push_back(special);
    }
    cout << special << endl;
    for (int i = 0; i < k; i++) {
    	for (int x : ans[i]) {
    		cout << x << " ";
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
