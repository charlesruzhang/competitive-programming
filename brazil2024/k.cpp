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
    vi x(10001);
    x[0] = 1;
    vi last(10001);
    last[0] = -1;
    for (int i = 0; i < n; i++) {
    	for (int j = 10000; j >= a[i]; j--) {
    		if (x[j - a[i]]) {
    			if (!x[j]) {
    				x[j] = 1;
    				last[j] = i;	
    			}
    		}
    	}
    }
    int summ = accumulate(a.begin(), a.end(), 0);
    if (summ % 2 == 1 || (!x[summ / 2])) {
    	cout << -1 << endl;
    	return;
    }
    int cur = summ / 2;
    vi mark(n);
    while (cur) {
    	mark[last[cur]] = 1;
    	cur -= a[last[cur]];
    }
    int j = 0;
    int i = 0; 
    int t1 = 0;
    int t2 = 0;
    vi ans;
    while (1) {
    	while (i < n && !mark[i]) {
    		i++;
    	}
    	while (j < n && mark[j]) {
    		j++;
    	}
    	if (t1 <= t2) {
    		ans.push_back(a[i]);
    		t1 += a[i];
    		i++;
    	} else {
    		t2 += a[j];
    		ans.push_back(a[j]);
    		j++;
    	}
    	if (i >= n && j >= n) break;
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
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
