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
    vector<pii> a(n);
    vector<pii> vec(2 * n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;
    	vec[a[i].first] = {i, 0}; 
    }
    for (int i = 0; i < n; i++) {
    	cin >> a[i].second;
    	vec[a[i].second] = {i, 1};
    }
    vi done(2 * n + 1);
    int p1 = 0;
    int p2 = 0;
    int rev = 0;
    int flag = 0;
    int tot = 0;
    for (int i = 1; i <= 2 * n; i++) {
    	if (done[i]) continue;
    	auto [idx, dir] = vec[i];
    	int other;
    	if (dir == 0) {
    		other = a[idx].second;
    	} else {
    		other = a[idx].first;
    		rev ++;
    	}
    	if (other < p2) {
    		cout << "No" << endl;
    		return;
    	} 
    	done[i] = 1;
    	done[other] = 1;
    	p1 = i;
    	p2 = other;
    	tot ++;
    	if ((p2 == 2 * tot) && (tot % 2 == 1)) {
    		flag = 1;
    	}
    }
    if (!flag && (rev % 2 == 1)) {
    	cout << "No" << endl;
    	return;
    }
    cout << "Yes" << endl;
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
