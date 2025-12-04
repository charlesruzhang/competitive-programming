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
    int target = 0;
    int cur = 0;
    map<int, int> before;
   	map<int, int> now;
    int ans = 0;
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	now[a[i]] ++;
		if (now[a[i]] == 1 && before[a[i]] > 0) {
			cur++;
		}
		if (now[a[i]] == 1) {
			tot++;
		}
    	if (cur >= target) {
    		cur = 0;
    		target = tot;
    		tot = 0;
    		map<int,int> nm;
    		swap(now, before);
    		swap(nm, now);
    		ans++;
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
