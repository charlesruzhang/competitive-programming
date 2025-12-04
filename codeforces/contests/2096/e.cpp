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
    int tot = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'B') {
    		tot++;
    		if (i % 2) l++;
    	}
    }
    ll ans = 0;
    int cur1 = 0;
    int cur2 = 1;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
    	v[i] = s[i];
    }
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'B') {
    		if (i % 2) {
    			ans += (i - cur2) / 2;
    			swap(v[i], v[cur2]);
    			cur2 += 2;
    		} else {
    			ans += (i - cur1) / 2;
    			swap(v[i], v[cur1]);
    			cur1+=2;
    		}
    	}
    }
    int cur = min(cur1, cur2);
    for (int i = n-1; i >= 0; i--) {
    	//cout << i << " " << cur << endl;
    	//assert(cur < n);
    	if (i <= cur) break;
    	if (v[i] == 'B') {
    		ans += 1 + (i - cur) / 2;
    		swap(v[i], v[cur]);
    		cur += 2;
    	} 
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
