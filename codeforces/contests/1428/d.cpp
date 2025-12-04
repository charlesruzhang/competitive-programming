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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi V, W, X;
    vi used(n, -1);
    int last = n;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
    	if (a[i] == 0) continue;
    	st.push(i);
    	if (a[i] == 1) {
    		W.push_back(i);
    	}
    }
    if (st.empty()) {
    	cout << 0 << endl;
    	return;
    }
    int cur = 0;
    vector<pii> ans;
    for (int i = 0; i < n; i++) {
    	if (!a[i]) continue;
    	if (used[i] == -1) {
    		ans.push_back({cur, i});
    	} else {
    		assert(a[i] == 1);
    		continue;
    	}
    	while (st.size() && st.top() <= i) {
    		st.pop();
    	}
    	if (a[i] == 3) {
    		while (st.size() && st.top() < i) {
    			st.pop();
    		}
    		while (st.size() && used[st.top()] == 1) {
    			st.pop();
    		}
    		if (st.empty()) {
    			cout << -1 << endl;
    			return;
    		}
    		int x = st.top();
    		st.pop();
			ans.push_back({cur, x});
			cur += 1;
			continue;
    	} else if (a[i] == 2) {
    		while (W.size() && W.back() < i) {
    			W.pop_back();
    		}
    		if (W.size()) {
    			int x = W.back();
    			W.pop_back();
    			ans.push_back({cur, x});
    			used[x] = 1;
    			cur += 1;
    			continue;
    		} else {
    			cout << -1 << endl;
    			return;
    		}
    	} else {
    		cur++;
    	}
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
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
