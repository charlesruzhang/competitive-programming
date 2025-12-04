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
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    stack<int> st;
    vi ans(n);
    for (int i = 0; i < n; i++) {
    	while (!st.empty() && st.top() > a[i]) {
    		st.pop();
    	}
    	if (st.empty()) {
    		ans[i] = 1;
    	}
    	st.push(a[i]);
    }

    stack<int> st2;
    for (int i = n - 1; i >= 0; i--) {
    	while (!st2.empty() && st2.top() < a[i]) {
    		st2.pop();
    	}
    	if (st2.empty()) {
    		ans[i] = 1;
    	}
    	st2.push(a[i]);
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i];
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
